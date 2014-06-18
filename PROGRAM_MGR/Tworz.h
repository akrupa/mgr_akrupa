#ifndef TWORZ_H
#define TWORZ_H
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Wprowadzone.h"
using namespace std;

const string s_select ="SELECT ";
const string s_select_distinct =s_select+" DISTINCT";
const string s_from = "FROM ";
const string s_join = "JOIN ";
const string s_where ="WHERE "; 
const string s_and ="AND ";
const string s_on="ON ";
const string s_where_not_exists="WHERE NOT EXISTS ";
const string s_distinct="DISTINCT ";
const string s_drop_table="drop table if exists ";
const string s_create_table="CREATE TABLE ";
const string s_insert_into="insert into ";
const string s_truncate_table= "truncate table ";

const string p_intf="intf_";
const string p_stg="stg_";
const string p_promo="promo_";
const string p_kmap_from="kmap_from_";

const string f_script="script_";
const string f_create="create_";

const string f_sql=".sql";

const string r_sql =".sql";
const string r_sh  =".sh";
const string r_conf=".conf"; 

class Tworz {

private:
Wprowadzone* w;
vector<Tabela*>& d;
public:
Tworz(Wprowadzone* w);

ofstream& getZapis(string s);

void create_table();

void download();
void download(string site, string dane_do_pgloader);

void pgloader();
void pgloader(string tab);

void message_file_create(string );

string g_create_sequence(string tab);
string g_create_table(string prefix, string suffix);
string g_drop_table(string prefix , string suffix);
string g_insert_into(string prefix , string suffix);

string create_file_address(string prefix_file, string prefix_tab,  string tab, string type=".sql");

void create_tab_intf(Tabela* );
void create_tab_stg(Tabela*  );
void create_tab_promo(Tabela*);
void create_tab_fact(Tabela* );

void create_all_dimensions_tab(Tabela* );
void create_dimension(Tabela* t=NULL);

void insert(); 
void insert_stg(Tabela* );
void insert_kmap_dimension(Tabela* );
void insert_promo(Tabela* );
void insert_fact(Tabela* );



};

#endif
