drop table if exists stg_wymiar1;
drop sequence if exists wymiar1_kmap_seq CASCADE;
create sequence wymiar1_kmap_seq 
increment by 1
no minvalue
no maxvalue
start with 1
cache 1
cycle;

CREATE TABLE stg_wymiar1
(
  id_wymiar1 integer default nextval('wymiar1_kmap_seq')
,  atrybut varchar
);
