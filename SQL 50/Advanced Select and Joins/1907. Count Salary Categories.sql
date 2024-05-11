WITH CATEGORY AS(
    SELECT *, CASE WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            ELSE 'High Salary' END AS category
    FROM Accounts 
),
TEMP AS (
    SELECT 'Low Salary' AS category, 0 AS accounts_count
    UNION 
    SELECT 'Average Salary' AS category, 0 AS accounts_count
    UNION 
    SELECT 'High Salary' AS category, 0 AS accounts_count
)
SELECT T.category, COUNT(C.account_id) AS accounts_count
FROM CATEGORY C
RIGHT JOIN TEMP T ON T.category = C.category
GROUP BY T.category
