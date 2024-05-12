CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    SELECT DISTINCT S
    FROM (
        SELECT E1.salary AS S, DENSE_RANK() OVER (ORDER BY E1.salary DESC) AS rank
        FROM Employee E1
    )
    WHERE rank = N
  );
END;
$$ LANGUAGE plpgsql;