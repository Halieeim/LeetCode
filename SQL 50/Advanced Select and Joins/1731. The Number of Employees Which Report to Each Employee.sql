WITH G AS (
    SELECT reports_to, COUNT(*) AS reports_count, ROUND(AVG(age)) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to 
)
SELECT employee_id, name, reports_count, average_age
FROM Employees E
JOIN G ON E.employee_id = G.reports_to
ORDER BY employee_id