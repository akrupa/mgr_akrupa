insert into stg_wymiar4
(
  atrybut
)
SELECT 
  atrybut
FROM intf_wymiar4 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_wymiar4 s 
    WHERE 
        i.atrybut= s.atrybut
);
