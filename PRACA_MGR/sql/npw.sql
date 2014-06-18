insert into npw
(
  nazwa
)
select distinct
  nazwa
from stg_gpw s
where not exists
(
  select 1
  from npw  k
  where k.nazwa = s.nazwa
);

