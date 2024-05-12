-- Write your PostgreSQL query statement below
SELECT score, rank
FROM (
    SELECT id, score, DENSE_RANK() OVER (ORDER BY score DESC) AS rank
    FROM Scores
)
ORDER BY rank, score DESC