-- Write your PostgreSQL query statement below
SELECT contest_id, 
        ROUND(COUNT(R.user_id)::NUMERIC * 100 / (SELECT COUNT(DISTINCT user_id) FROM Users),2) 
        AS percentage 
FROM Users U
NATURAL JOIN Register R
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;