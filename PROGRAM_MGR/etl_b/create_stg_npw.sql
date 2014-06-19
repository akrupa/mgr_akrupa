drop table if exists stg_npw;
drop sequence if exists npw_kmap_seq CASCADE;
create sequence npw_kmap_seq 
increment by 1
no minvalue
no maxvalue
start with 1
cache 1
cycle;

CREATE TABLE stg_npw
(
  id_npw integer default nextval('npw_kmap_seq')
,  data_od timestamp
, data_do timestamp
, nazwa varchar(50)
, opis varchar(200)
);
