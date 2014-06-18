drop table if exists intf_gpw;
CREATE TABLE intf_gpw
(
  nazwa varchar(50)
, data_notowania date
, otwarcie decimal(20,2)
, max decimal(20,2)
, min decimal(20,2)
, zamkniecie decimal(20,2)
, wartosc decimal(20,3)
);
