drop table if exists public.gpw;
create table public.gpw
(
  npw_id integer
, data_notowania date
, otwarcie decimal(20, 2)
, max  decimal(20, 2)
, min decimal(20, 2)
, zamkniecie decimal(20, 2)
, wartosc decimal(20,3)
);
