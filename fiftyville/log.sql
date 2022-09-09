-- Keep a log of any SQL queries you execute as you solve the mystery.

--Use to get a list of all the tables and their categories
--.schema

-- Get the number of people in the town - 200
-- SELECT count(name) FROM people

-- Get number of flights - 58
-- SELECT COUNT(id) FROM flights

-- Get a list of all the airports and their names
--SELECT distinct destination_airport_id, full_name
--FROM flights
--INNER JOIN airports
--    on flights.destination_airport_id = airports.id
--ORDER BY destination_airport_id

-- Get a list of all the airports city locations
-- SELECT distinct destination_airport_id, city
-- FROM flights
-- INNER JOIN airports
--     on flights.destination_airport_id = airports.id
-- ORDER BY destination_airport_id

--Get reports for crimes on humprey street and on July 28th
--SELECT * FROM crime_scene_reports
--WHERE street = 'Humprey Street'
--
--SELECT * FROM crime_scene_reports
--WHERE month = 7 AND day = 28

-- see which interviews mention the bakery
--SELECT * FROM interviews
--WHERE month = 7 AND day = 28

-- Narrow to specific interviews relating to the crime
-- SELECT id, name, transcript
-- FROM interviews
-- WHERE id BETWEEN 161 AND 163

--See what time Eugene got to the bakery
-- SELECT hour, minute, activity, bakery_security_logs.license_plate, people.name FROM bakery_security_logs
-- INNER JOIN people
--     ON bakery_security_logs.license_plate = people.license_plate
-- WHERE people.name = 'Eugene'

--check bakery footage and get names of attached to cars
-- SELECT hour, minute, activity, bakery_security_logs.license_plate, people.name FROM bakery_security_logs
-- INNER JOIN people
--     ON bakery_security_logs.license_plate = people.license_plate
-- WHERE people.name = 'Bruce' OR people.name = 'Diana'

-- Check atm transactions
-- SELECT atm_transactions.id, atm_transactions.account_number, transaction_type, amount, people.name FROM atm_transactions
-- INNER JOIN bank_accounts
--     ON atm_transactions.account_number = bank_accounts.account_number
-- INNER JOIN people
--     ON bank_accounts.person_id = people.id
-- WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street'

-- Narrowed down suspects to Bruce, Diana, Iman, and Luca, see who got on a flight out of fiftyville the next day
-- SELECT passengers.passport_number, people.name from passengers
-- INNER JOIN people
--     ON passengers.passport_number = people.passport_number
-- WHERE flight_id IN
-- (SELECT id FROM flights
-- WHERE origin_airport_id = 8 AND month = 7 AND day = 29)
-- ORDER BY people.name

-- Further narrow downt the suspects and see who they called
-- SELECT caller,receiver,duration, people.name FROM phone_calls
-- INNER JOIN people
--     on phone_calls.receiver = people.phone_number
-- WHERE month = 7 AND day = 28 AND duration < 60

-- See who was on the earlier flight between Diana and Bruce
--SELECT passengers.passport_number, people.name from passengers
--INNER JOIN people
--    ON passengers.passport_number = people.passport_number
--WHERE flight_id IN
--(SELECT id FROM flights
--WHERE id = 18)

-- Check flight information of flight Diana was on
-- SELECT * FROM flights
-- WHERE id = 18

-- Was not Diana check bakery security to see who got there earlier and compare with atm transactions to see whose was earlier
--check bakery footage and get names of attached to cars
-- SELECT hour, minute, activity, bakery_security_logs.license_plate, people.name FROM bakery_security_logs
-- INNER JOIN people
--     ON bakery_security_logs.license_plate = people.license_plate
-- WHERE people.name = 'Bruce' OR people.name = 'Diana'

-- SELECT passengers.passport_number, people.name, flights.id from passengers
-- INNER JOIN people
--     ON passengers.passport_number = people.passport_number
-- INNER JOIN flights
--     ON passengers.flight_id = flights.id
-- WHERE flight_id IN
-- (SELECT id FROM flights
-- WHERE origin_airport_id = 8 AND month = 7 AND day = 29)
-- AND people.passport_number = 5773159633

-- Check flight information of flight Bruce was on
-- SELECT * FROM flights
-- WHERE id = 36
