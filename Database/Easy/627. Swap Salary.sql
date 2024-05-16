-- Write your PostgreSQL query statement below
UPDATE Salary
SET sex = CASE WHEN SEX = 'm' THEN 'f' ELSE 'm' END