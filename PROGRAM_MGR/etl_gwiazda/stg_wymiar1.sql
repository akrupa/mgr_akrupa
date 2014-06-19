insert into stg_wymiar1
(
  atrybut
)
SELECT 
  atrybut
FROM intf_wymiar1 i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_wymiar1 s 
    WHERE 
        i.atrybut= s.atrybut
);
