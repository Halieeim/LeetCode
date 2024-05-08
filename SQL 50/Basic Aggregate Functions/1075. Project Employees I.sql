-- Write your PostgreSQL query statement below
SELECT p.project_id, ROUND(AVG(experience_years),2) AS average_years
FROM Project p
NATURAL JOIN Employee
GROUP BY p.project_id;