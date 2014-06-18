insert into npw
(
nazwa
)
SELECT  DISTINCT
nazwa
FROM stg_gpw s 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM  npw k 
    WHERE  s.nazwa = k.nazwa
)
