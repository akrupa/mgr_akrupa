DROP TABLE IF EXISTS fakt;
DROP TABLE IF EXISTS wymiar1;
DROP TABLE IF EXISTS wymiar2;
DROP TABLE IF EXISTS wymiar3;
DROP TABLE IF EXISTS wymiar4;
CREATE TABLE wymiar1
(
  id_wymiar1 integer PRIMARY KEY
, atrybut varchar
);

CREATE TABLE wymiar2
(
  id_wymiar2 integer PRIMARY KEY
, atrybut_1 varchar
, atrybut_2 numeric 
);

CREATE TABLE wymiar3
(
  id_wymiar3 integer PRIMARY KEY
, atrybut varchar
);

CREATE TABLE wymiar4
(
  id_wymiar4 integer PRIMARY KEY
, atrybut varchar
);

CREATE TABLE fakt 
(
  id_wymiar1 integer  references wymiar1(id_wymiar1)
, id_wymiar2 integer  references wymiar2(id_wymiar2)
, id_wymiar3 integer  references wymiar3(id_wymiar3)
, id_wymiar4 integer  references wymiar4(id_wymiar4)
, data       timestamp not null
, miara_1    integer  not null
, miara_2    integer  not null
);
