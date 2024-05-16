SELECT name, SUM(amount) AS balance
FROM Users NATURAL JOIN Transactions 
GROUP BY name HAVING SUM(amount) > 10000;