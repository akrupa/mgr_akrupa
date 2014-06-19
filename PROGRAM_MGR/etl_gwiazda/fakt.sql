insert into fakt
(
  id_wymiar1
, id_wymiar2
, id_wymiar3
, id_wymiar4
, data
, miara_1
, miara_2
)
SELECT 
  id_wymiar1
, id_wymiar2
, id_wymiar3
, id_wymiar4
, data
, miara_1
, miara_2
FROM promo_fakt i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM fakt s 
    WHERE 
        i.id_wymiar1= s.id_wymiar1
    and i.id_wymiar2= s.id_wymiar2
    and i.id_wymiar3= s.id_wymiar3
    and i.id_wymiar4= s.id_wymiar4
);
