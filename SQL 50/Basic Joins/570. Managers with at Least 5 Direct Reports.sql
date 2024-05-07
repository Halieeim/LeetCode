-- Write your PostgreSQL query statement below
SELECT E2.name
FROM Employee E1
JOIN Employee E2 ON E1.managerId = E2.id
GROUP BY E2.id,E2.name HAVING COUNT(*) >= 5;