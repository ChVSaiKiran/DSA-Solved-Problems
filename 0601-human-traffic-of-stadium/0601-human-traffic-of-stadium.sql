/* Write your PL/SQL query statement below */
WITH Q AS (
    SELECT ID FROM STADIUM WHERE PEOPLE >= 100
),

TEMP AS(
    SELECT S1.ID AS ID1, S2.ID AS ID2, S3.ID AS ID3
    FROM Q S1 
    JOIN Q S2 ON S1.ID + 1 = S2.ID
    JOIN Q S3 ON S2.ID + 1 = S3.ID
),

IDS AS(
    SELECT ID1 AS ID FROM TEMP UNION
    SELECT ID2 AS ID FROM TEMP UNION
    SELECT ID3 AS ID FROM TEMP
)

SELECT STADIUM.ID, TO_CHAR(VISIT_DATE, 'YYYY-MM-DD') AS VISIT_DATE, PEOPLE 
FROM STADIUM JOIN IDS ON STADIUM.ID = IDS.ID
ORDER BY VISIT_DATE;