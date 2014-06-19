

psql -f ./etl_gwiazda/create_intf_fakt.sql
psql -f ./etl_gwiazda/create_stg_fakt.sql
psql -f ./etl_gwiazda/create_promo_fakt.sql
psql -f ./etl_gwiazda/create_fakt.sql
psql -f ./etl_gwiazda/create_intf_wymiar1.sql
psql -f ./etl_gwiazda/create_stg_wymiar1.sql
psql -f ./etl_gwiazda/create_wymiar1.sql
psql -f ./etl_gwiazda/create_intf_wymiar2.sql
psql -f ./etl_gwiazda/create_stg_wymiar2.sql
psql -f ./etl_gwiazda/create_wymiar2.sql
psql -f ./etl_gwiazda/create_intf_wymiar3.sql
psql -f ./etl_gwiazda/create_stg_wymiar3.sql
psql -f ./etl_gwiazda/create_wymiar3.sql
psql -f ./etl_gwiazda/create_intf_wymiar4.sql
psql -f ./etl_gwiazda/create_stg_wymiar4.sql
psql -f ./etl_gwiazda/create_wymiar4.sql

#----------------------------- Tworzy tabele ---------------------- 
#iTworzenie  procesów dotyczące warstwy pośredniej i docelowej 
psql -f ./etl_gwiazda/stg_fakt.sql
psql -f ./etl_gwiazda/stg_wymiar1.sql
psql -f ./etl_gwiazda/stg_wymiar2.sql
psql -f ./etl_gwiazda/stg_wymiar3.sql
psql -f ./etl_gwiazda/stg_wymiar4.sql
psql -f ./etl_gwiazda/promo_fakt.sql
psql -f ./etl_gwiazda/wymiar1.sql
psql -f ./etl_gwiazda/wymiar2.sql
psql -f ./etl_gwiazda/wymiar3.sql
psql -f ./etl_gwiazda/wymiar4.sql
psql -f ./etl_gwiazda/fakt.sql
#Koniec  Tworzenia procesów dotyczące warstwy pośredniej i docelowej 



#------------------ Koniec tworzenia procesów. 
