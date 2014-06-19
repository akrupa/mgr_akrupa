insert into stg_npw
(
  data_od
, data_do
, nazwa
, opis
)
SELECT 
  data_od
, data_do
, nazwa
, opis
FROM intf_npw i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_npw s 
    WHERE 
        i.nazwa= s.nazwa
);
