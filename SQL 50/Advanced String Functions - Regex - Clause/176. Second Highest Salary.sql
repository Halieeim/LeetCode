-- Write your PostgreSQL query statement below
SELECT MAX(salary) AS SecondHighestSalary 
FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rank
    FROM Employee
)
WHERE rank = 2