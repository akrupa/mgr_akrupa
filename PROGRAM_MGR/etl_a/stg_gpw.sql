insert into stg_gpw
(
  nazwa
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
)
SELECT 
  nazwa
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
FROM intf_gpw i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM stg_gpw s 
    WHERE 
        i.nazwa= s.nazwa
    and i.data_notowania= s.data_notowania
);
