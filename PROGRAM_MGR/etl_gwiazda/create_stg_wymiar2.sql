drop table if exists stg_wymiar2;
drop sequence if exists wymiar2_kmap_seq CASCADE;
create sequence wymiar2_kmap_seq 
increment by 1
no minvalue
no maxvalue
start with 1
cache 1
cycle;

CREATE TABLE stg_wymiar2
(
  id_wymiar2 integer default nextval('wymiar2_kmap_seq')
,  atrybut_1 varchar
, atrybut_2 numeric
);
