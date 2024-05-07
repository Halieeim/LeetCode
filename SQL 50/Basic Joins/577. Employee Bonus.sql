-- Write your PostgreSQL query statement below
SELECT name , bonus 
FROM Employee e
LEFT JOIN Bonus b ON e.empid = b.empid
WHERE bonus < 1000 OR bonus IS NULL;