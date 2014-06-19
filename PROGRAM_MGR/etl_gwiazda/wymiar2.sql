insert into wymiar2
(
id_wymiar2
,  atrybut_1
,  atrybut_2
)
SELECT 
id_wymiar2
, atrybut_1
, atrybut_2
FROM stg_wymiar2 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM wymiar2 s 
    WHERE 
       i.id_wymiar2= s.id_wymiar2
);
