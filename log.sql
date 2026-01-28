-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get the crime description
SELECT description
FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Get the transcript of the interview
SELECT name, transcript
FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28;


-- Get the origin_airport_id
SELECT id
FROM airports
WHERE full_name =
(
    SELECT full_name
    FROM airports
    WHERE city = 'Fiftyville'
);
-- 8

-- Get the time and destination_airport_id
SELECT hour, minute, destination_airport_id
FROM flights
WHERE origin_airport_id = 8
AND year = 2025
AND month = 7
AND day = 29
ORDER BY hour, minute
LIMIT 1;
-- 8, 20, 4

-- 2. Get the final destination city the thief escaped to
SELECT city
FROM airports
WHERE id = 4;
--New York City


-- 1. Get the name of the thief from people, using phone_number, passport_number and license_plate
SELECT name
FROM people
WHERE id IN
(
    --Get the possible person_id(id in people)
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2025
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND phone_number IN
(
    -- Get the caller whose call's duration was less than a minute around 10:15am on that day
    SELECT caller
    FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
)
AND passport_number IN
(
    -- Get the possible passport_number from passengers
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
    (
        -- Get the id(flight_id in passengers) from flights
        SELECT id
        FROM flights
        WHERE origin_airport_id = 8
        AND year = 2025
        AND month = 7
        AND day = 29
        AND hour = 8
        AND minute = 20
    )
)
AND license_plate IN
(
    -- Get the possible licenses of car
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
    AND activity = 'exit'
);
-- Bruce


-- 3. Get the name of the accomplice
SELECT name
FROM people
WHERE phone_number =
(
    SELECT receiver
    FROM phone_calls
    WHERE caller =
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
);
-- Robin
