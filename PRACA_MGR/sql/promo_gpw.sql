truncate table promo_gpw;
insert into  promo_gpw
(
  npw_id
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
)
select 
  n.npw_id
, s.data_notowania
, s.otwarcie
, s.max
, s.min
, s.zamkniecie
, s.wartosc
from stg_gpw s
join npw n  on n.nazwa=s.nazwa
;

