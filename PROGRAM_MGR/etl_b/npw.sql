insert into npw
(
id_npw
,  data_od
,  data_do
,  nazwa
,  opis
)
SELECT 
id_npw
, data_od
, data_do
, nazwa
, opis
FROM stg_npw i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM npw s 
    WHERE 
       i.id_npw= s.id_npw
);
