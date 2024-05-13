WITH VALID AS (
    SELECT E.employee_id
    FROM Employees E
    JOIN Salaries S ON E.employee_id = S.employee_id
), 
ALL_IDs AS(
    SELECT employee_id FROM Employees
    UNION 
    SELECT employee_id FROM Salaries 
)
(
    SELECT * FROM ALL_IDs
    EXCEPT
    SELECT * FROM VALID
)
ORDER BY employee_id