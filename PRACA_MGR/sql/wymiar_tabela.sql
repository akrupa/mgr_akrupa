drop table if exists npw;
drop sequence if exists npw_kmap_seq;
create sequence  npw_kmap_seq
  increment by 1
  no minvalue
  no maxvalue
  start with 1
  cache 1
  cycle;

create table npw
(
  npw_id integer default nextval('npw_kmap_seq')
, nazwa varchar(50)
);
