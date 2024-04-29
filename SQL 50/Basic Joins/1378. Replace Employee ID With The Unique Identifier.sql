/* Write your T-SQL query statement below */
SELECT EmployeeUNI.unique_id, Employees.name
FROM EmployeeUNI
right JOIN Employees ON Employees.id = EmployeeUNI.id;