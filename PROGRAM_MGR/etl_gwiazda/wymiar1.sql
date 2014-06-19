insert into wymiar1
(
id_wymiar1
,  atrybut
)
SELECT 
id_wymiar1
, atrybut
FROM stg_wymiar1 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM wymiar1 s 
    WHERE 
       i.id_wymiar1= s.id_wymiar1
);
