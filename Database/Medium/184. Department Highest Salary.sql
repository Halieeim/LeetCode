WITH ranking AS (
    SELECT D.name AS "Department", E.name AS "Employee", salary AS "Salary", 
        DENSE_RANK() OVER(PARTITION BY D.id ORDER BY salary DESC) AS rank
    FROM Employee E
    JOIN Department D ON E.departmentid = D.id
)
SELECT "Department", "Employee", "Salary"
FROM ranking
WHERE rank = 1;