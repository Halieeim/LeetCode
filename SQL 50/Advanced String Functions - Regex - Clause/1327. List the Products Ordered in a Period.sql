-- Write your PostgreSQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM Products
NATURAL JOIN Orders
WHERE order_date BETWEEN DATE '2020-02-01' AND DATE '2020-02-29'
GROUP BY product_name HAVING SUM(unit) >= 100;