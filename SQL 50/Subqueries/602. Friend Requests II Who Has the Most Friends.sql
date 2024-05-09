WITH reqs AS (
    SELECT requester_id AS id, COUNT(*) AS num
    FROM RequestAccepted 
    GROUP BY requester_id
),
ac AS (
    SELECT accepter_id AS id, COUNT(*) AS num
    FROM RequestAccepted 
    GROUP BY accepter_id 
),
un AS(
    SELECT * FROM reqs
    UNION ALL
    SELECT * FROM ac
),
res AS(
    SELECT id, SUM(num) AS sums
    FROM un
    GROUP BY id
    ORDER BY sums DESC
)
SELECT id, sums AS num FROM res LIMIT 1;

-- SIMPLER SOLUTION

WITH all_ids AS(
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
)
SELECT id, COUNT(*) AS num
FROM all_ids
GROUP BY id
ORDER BY num DESC
LIMIT 1;
