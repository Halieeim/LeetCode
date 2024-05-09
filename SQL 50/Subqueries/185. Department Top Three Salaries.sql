WITH RankedSalaries AS (
    SELECT DISTINCT D.name,
           salary,
           DENSE_RANK() OVER (PARTITION BY D.name ORDER BY Salary DESC) AS rank
    FROM Employee E
    JOIN Department D ON D.id = E.departmentId 
),
J AS (
    SELECT D.id,E.name,salary,D.name AS dep_name FROM Employee E
    JOIN Department D ON E.departmentId = D.id
)
SELECT R.name AS "Department", J.name AS Employee, J.salary AS "Salary" 
FROM RankedSalaries R 
JOIN J ON R.salary = J.salary AND R.name = J.dep_name
WHERE rank <= 3;