SELECT X, Y, Z, CASE WHEN (X+Y) > Z
    AND (X+Z) > Y AND (Z+Y) > X THEN 'Yes' ELSE 'No' END AS triangle 
FROM Triangle 