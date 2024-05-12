WITH consecutive_counts AS (
    SELECT 
        id,
        visit_date,
        people,
        LAG(people,2) OVER (ORDER BY id) AS prev_prev_people,
        LAG(people) OVER (ORDER BY id) AS prev_people,
        LEAD(people) OVER (ORDER BY id) AS next_people,
        LEAD(people,2) OVER (ORDER BY id) AS next_next_people
    FROM 
        Stadium
)
SELECT 
    id,
    visit_date,
    people
FROM 
    consecutive_counts
WHERE 
    (people >= 100 AND (next_people >= 100 AND next_next_people >= 100))
    OR (people >= 100 AND (prev_people >= 100 AND next_people >= 100))
    OR (people >= 100 AND (prev_prev_people >= 100 AND prev_people >= 100))
ORDER BY 
    visit_date;