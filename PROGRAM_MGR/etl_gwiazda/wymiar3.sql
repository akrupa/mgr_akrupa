insert into wymiar3
(
id_wymiar3
,  atrybut
)
SELECT 
id_wymiar3
, atrybut
FROM stg_wymiar3 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM wymiar3 s 
    WHERE 
       i.id_wymiar3= s.id_wymiar3
);
