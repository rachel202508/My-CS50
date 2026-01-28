-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
SELECT DISTINCT name
FROM people
WHERE id IN
(
    SELECT DISTINCT person_id
    FROM directors
    WHERE movie_id IN
    (
        SELECT DISTINCT movie_id
        FROM ratings
        WHERE rating >= 9.0
    )
);
