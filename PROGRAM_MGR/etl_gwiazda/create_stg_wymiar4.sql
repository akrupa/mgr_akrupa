drop table if exists stg_wymiar4;
drop sequence if exists wymiar4_kmap_seq CASCADE;
create sequence wymiar4_kmap_seq 
increment by 1
no minvalue
no maxvalue
start with 1
cache 1
cycle;

CREATE TABLE stg_wymiar4
(
  id_wymiar4 integer default nextval('wymiar4_kmap_seq')
,  atrybut varchar
);
