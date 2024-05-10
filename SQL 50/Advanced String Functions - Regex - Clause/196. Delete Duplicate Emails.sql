-- Write your PostgreSQL query statement below
DELETE FROM Person
WHERE id NOT IN (
    SELECT id
    FROM (
        SELECT id, DENSE_RANK() OVER (PARTITION BY email ORDER BY id) AS rank
        FROM Person
    )
    WHERE rank = 1
)