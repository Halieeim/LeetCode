SELECT visited_on, amount, average_amount 
FROM (
    SELECT
        visited_on,
        SUM(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(AVG(amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW)::numeric, 2) AS average_amount
    FROM (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
        ORDER BY visited_on
    )
)
WHERE visited_on >= (SELECT MIN(visited_on) FROM Customer) + INTERVAL '6 DAYS'
ORDER BY visited_on;
