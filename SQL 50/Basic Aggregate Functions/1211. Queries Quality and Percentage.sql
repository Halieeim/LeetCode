-- Write your PostgreSQL query statement below
SELECT query_name, 
        ROUND(AVG(rating / position::NUMERIC),2) AS quality, 
        ROUND(COALESCE((SELECT COUNT(*) FROM Queries Q 
        WHERE Q.rating < 3 AND Q.query_name = QU.query_name) * 100 / NULLIF((SELECT COUNT(*) FROM Queries Q 
        WHERE Q.query_name = QU.query_name)::NUMERIC,0),0),2) AS poor_query_percentage
FROM Queries QU
WHERE QU.query_name IS NOT NULL
GROUP BY query_name;