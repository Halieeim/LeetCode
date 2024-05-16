-- Write your PostgreSQL query statement below
WITH J AS(
    SELECT buyer_id, join_date, order_date
    FROM Users U LEFT JOIN Orders O ON user_id = buyer_id
    WHERE EXTRACT(YEAR FROM order_date) = 2019
)
SELECT user_id AS buyer_id, U.join_date, SUM(CASE WHEN buyer_id IS NULL THEN 0 ELSE 1 END) AS orders_in_2019 
FROM Users U LEFT JOIN J ON user_id = buyer_id
GROUP BY user_id, U.join_date