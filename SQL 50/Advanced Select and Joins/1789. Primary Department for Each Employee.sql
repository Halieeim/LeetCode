WITH COUNTING AS (
    SELECT employee_id, COUNT(*) AS CNT
    FROM Employee
    GROUP BY employee_id
),
J AS (
    SELECT employee_id, department_id, CNT, primary_flag 
    FROM Employee
    NATURAL JOIN COUNTING
)
SELECT employee_id, department_id
FROM J
WHERE CNT = 1 OR (CNT > 1 AND primary_flag = 'Y')