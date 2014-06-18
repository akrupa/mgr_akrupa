#!/bin/bash

psql -f ./tworz_intf_gpw.sql
psql -f ./tworz_stg_gpw.sql
psql -f ./tworz_promo_gpw.sql
psql -f ./fakt_tabela.sql
psql -f ./wymiar_tabela.sql
