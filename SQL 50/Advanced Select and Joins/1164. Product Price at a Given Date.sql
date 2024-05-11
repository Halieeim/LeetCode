WITH J AS (
    SELECT L1.product_id, L1.new_price, L1.change_date
    FROM Products L1
    JOIN Products L2 ON L1.product_id = L2.product_id AND L1.change_date <= L2.change_date AND
        L2.change_date <= DATE '2019-08-16'
),
IDS AS (
    SELECT product_id , MAX(change_date) AS change_date
    FROM J
    GROUP BY product_id
)
K AS(
    SELECT product_id, 
        CASE WHEN (product_id) NOT IN (SELECT product_id FROM IDS) THEN 10 
        WHEN (product_id, change_date) IN (SELECT * FROM IDS) THEN new_price
        END AS price
    FROM Products
)
SELECT DISTINCT * FROM K WHERE price IS NOT NULL