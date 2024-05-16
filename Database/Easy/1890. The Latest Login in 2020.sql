WITH EXC AS (
    SELECT * FROM Logins WHERE EXTRACT(YEAR FROM time_stamp) = 2020
)
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM EXC
GROUP BY user_id 