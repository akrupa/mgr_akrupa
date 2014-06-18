insert into  gpw
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
  npw_id
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
from promo_gpw p
where not exists 
(
  select
    1
  from gpw t
  where
       t.npw_id=p.npw_id 
  and  t.data_notowania=p.data_notowania
);
