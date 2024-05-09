SELECT ROUND(SUM(tiv_2016)::NUMERIC, 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)
AND (lat, lon) NOT IN (
    SELECT lat, lon
    FROM (
        SELECT lat, lon, COUNT(*) AS occurances
        FROM Insurance
        GROUP BY lat, lon
    ) 
    WHERE occurances > 1
);
