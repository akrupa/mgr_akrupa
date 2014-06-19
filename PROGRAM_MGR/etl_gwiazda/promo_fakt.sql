truncate table promo_fakt;
insert into promo_fakt
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
  a.id_wymiar1
, b.id_wymiar2
, c.id_wymiar3
, d.id_wymiar4
, s.data
, s.miara_1
, s.miara_2
FROM stg_fakt s 
JOIN wymiar1 a ON a.id_wymiar1 = s.id_wymiar1
JOIN wymiar2 b ON b.id_wymiar2 = s.id_wymiar2
JOIN wymiar3 c ON c.id_wymiar3 = s.id_wymiar3
JOIN wymiar4 d ON d.id_wymiar4 = s.id_wymiar4
;
