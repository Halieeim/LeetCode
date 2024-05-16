SELECT DISTINCT product_id, product_name
FROM Product P NATURAL JOIN Sales S
WHERE product_id NOT IN (SELECT product_id FROM Sales 
                            WHERE sale_date NOT BETWEEN DATE '2019-01-01' AND DATE '2019-03-31')