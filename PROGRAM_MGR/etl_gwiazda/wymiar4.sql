insert into wymiar4
(
id_wymiar4
,  atrybut
)
SELECT 
id_wymiar4
, atrybut
FROM stg_wymiar4 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM wymiar4 s 
    WHERE 
       i.id_wymiar4= s.id_wymiar4
);
