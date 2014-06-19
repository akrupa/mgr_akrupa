insert into stg_wymiar3
(
  atrybut
)
SELECT 
  atrybut
FROM intf_wymiar3 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_wymiar3 s 
    WHERE 
        i.atrybut= s.atrybut
);
