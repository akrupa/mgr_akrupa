insert into stg_wymiar2
(
  atrybut_1
, atrybut_2
)
SELECT 
  atrybut_1
, atrybut_2
FROM intf_wymiar2 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_wymiar2 s 
    WHERE 
        i.atrybut_1= s.atrybut_1
);
