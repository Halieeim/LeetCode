SELECT name, SUM(CASE WHEN distance IS NULL THEN 0 ELSE distance END) AS travelled_distance
FROM Users U LEFT JOIN Rides R ON U.id = R.user_id 
GROUP BY name, U.id
ORDER BY travelled_distance DESC, name;