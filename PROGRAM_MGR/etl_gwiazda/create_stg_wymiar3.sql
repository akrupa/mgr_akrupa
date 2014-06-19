drop table if exists stg_wymiar3;
drop sequence if exists wymiar3_kmap_seq CASCADE;
create sequence wymiar3_kmap_seq 
increment by 1
no minvalue
no maxvalue
start with 1
cache 1
cycle;

CREATE TABLE stg_wymiar3
(
  id_wymiar3 integer default nextval('wymiar3_kmap_seq')
,  atrybut varchar
);
