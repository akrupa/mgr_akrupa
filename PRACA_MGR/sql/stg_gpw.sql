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
select
  nazwa
, data_notowania
, otwarcie
, max
, min
, zamkniecie
, wartosc
from intf_gpw i
where not exists
(
  select 1
  from stg_gpw s
  where s.nazwa = i.nazwa
    and s.data_notowania = i.data_notowania
);

