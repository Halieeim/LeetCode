-- Write your PostgreSQL query statement below
WITH J1 AS (
    SELECT MR.movie_id, title, user_id, rating, created_at
    FROM Movies M
    JOIN MovieRating MR ON M.movie_id = MR.movie_id
),
J2 AS (
    SELECT J1.movie_id,title, name, J1.user_id, rating, created_at
    FROM Users U
    JOIN J1 ON U.user_id = J1.user_id
),
avgR AS (
    SELECT movie_id, AVG(rating)::NUMERIC AS avg
    FROM J2
    WHERE EXTRACT(YEAR FROM created_at) = 2020 AND EXTRACT(MONTH FROM created_at) = 2
    GROUP BY movie_id
),
maxR AS (
    SELECT user_id, COUNT(*) AS CNT
    FROM J2
    GROUP BY user_id
),
Q1 AS (
    SELECT J2.name AS results FROM maxR,J2 WHERE maxR.user_id = J2.user_id
    ORDER BY CNT DESC, J2.name LIMIT 1
),
Q2 AS (
    SELECT J2.title AS results FROM avgR, J2 WHERE avgR.movie_id = J2.movie_id
    ORDER BY avg DESC, J2.title LIMIT 1
)
SELECT * FROM Q1
UNION ALL
SELECT * FROM Q2;
