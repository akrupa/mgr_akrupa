insert into gpw
(
  id_npw
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
)
SELECT 
  id_npw
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
FROM promo_gpw i 
WHERE NOT EXISTS 
(
    SELECT  1 
    FROM gpw s 
    WHERE 
        i.nazwa= s.nazwa
    and i.data_notowania= s.data_notowania
);
