WITH ExecludeBanned AS (
    SELECT * FROM Trips
    WHERE (client_id) NOT IN (
        SELECT users_id FROM Users
        WHERE banned = 'Yes' AND role = 'client'
    )
    AND (driver_id) NOT IN (
        SELECT users_id FROM Users
        WHERE banned = 'Yes' AND role = 'driver'
    )
    AND request_at::DATE BETWEEN DATE '2013-10-01' AND DATE '2013-10-03'
)
SELECT request_at AS "Day", 
ROUND(AVG(CASE WHEN status LIKE 'cancelled%' THEN 1 ELSE 0 END)::NUMERIC,2) AS "Cancellation Rate"
FROM ExecludeBanned
GROUP BY request_at