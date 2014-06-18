drop table if exists promo_gpw;
CREATE TABLE promo_gpw
(
  id_npw integer
, data_notowania date
, otwarcie decimal(20,2)
, max decimal(20,2)
, min decimal(20,2)
, zamkniecie decimal(20,2)
, wartosc decimal(20,3)
);
