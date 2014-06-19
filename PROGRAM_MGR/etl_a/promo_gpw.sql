truncate table promo_gpw;
insert into promo_gpw
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
  a.id_npw
, s.data_notowania
, s.otwarcie
, s.max
, s.min
, s.zamkniecie
, s.wartosc
FROM stg_gpw s 
JOIN npw a ON a.nazwa = s.nazwa
;
