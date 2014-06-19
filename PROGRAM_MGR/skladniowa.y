%{
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "Wprowadzone.h" 


extern Wprowadzone *w;
int a_exit=0;
int a_error_yacc=0;
int a_yacc_polecenie=0;


string str_rob;
Columna* wsk_k=NULL;
Tabela* wsk_tabela=NULL;
string a_yacc_string="";
string a_yacc_string_dwa="";

extern "C" int yyparse(void);
extern "C" int yylex(void);  
extern "C" int yywrap() {return 1;}



void yyerror(const char *str)
{
printf("Error: Wystąpił błąd polecenia.\n");
a_error_yacc=1;
}
%}


%token EXIT  SAVE_DIR TABLE_NAME BASE_NAME USER_NAME
%token MAKE
%token NUMBER IDENTIFIER 
%token CREATE KEY FACT DIMENSION SITE_WEB SITE_WEB_ADDRESS PGLOADER
%token  LEFTPARENTHESIS RIGHTPARENTHESIS  SEMICOLON COMMA  LEX_ERROR 





%%

y_polecenie_srednik:
  y_polecenie SEMICOLON { }   
;
y_polecenie:
  EXIT {  a_exit=1;   }
  |
  MAKE { a_yacc_polecenie=1; }
  |
  SAVE_DIR IDENTIFIER {w->setSave_dir( (char*) $2 ); }
  |
  USER_NAME IDENTIFIER	{w->setName_user((char*) $2);}
  |
  BASE_NAME IDENTIFIER	{w->setName_base((char*) $2);}
  |
  SITE_WEB SITE_WEB_ADDRESS IDENTIFIER 
	{ 
	 a_yacc_string = (char*) $2;
	 a_yacc_string_dwa= (char*) $3;
	 a_yacc_polecenie=2; 
	 }
  |
  PGLOADER IDENTIFIER  {a_yacc_string = (char*) $2; a_yacc_polecenie=3; }
  | 
  y_fakt_polecenie 
  |
  y_wymiar_polecenie
;

y_fakt_polecenie:
  CREATE FACT IDENTIFIER LEFTPARENTHESIS y_list_fact_kolumn RIGHTPARENTHESIS
	{
	w->getFact()->setName_tab( (char*) $3 );
	}
;

y_list_fact_kolumn:
 y_fact_kolumna COMMA y_list_fact_kolumn {  w->getFact()->add( (Columna*) $1);   }
 |
 y_fact_kolumna {  w->getFact()->add( (Columna*) $1);   }
;



y_fact_kolumna:
 y_prosta  {$$=$1;}
|
 y_prosta KEY 
	{
	((Columna*) $1)->setTyp(1);
	$$=$1;
	}	 
|
 y_prosta DIMENSION IDENTIFIER
	{
	((Columna*) $1)->setTyp(2);
	((Columna*) $1)->setNameColumnaWymiar((char*) $3 );
	$$=$1;
	}	 

;

y_wymiar_polecenie:
  CREATE DIMENSION IDENTIFIER LEFTPARENTHESIS y_list_wymiar_kolumn RIGHTPARENTHESIS 
	{
	  if (wsk_tabela==NULL) {
		cout << "ERROR YACC: Błąd tworzenia tablicy wymiarów " << endl;
	  } else {
 		wsk_tabela->setName_tab( (char*) $3 );
		w->addWymiar(wsk_tabela);
		wsk_tabela=NULL;	
   	  }
	
	}
;



y_list_wymiar_kolumn:
 y_wymiar_kolumna COMMA y_list_wymiar_kolumn 
 	{
 	 wsk_tabela->add((Columna*) $1);
 	}
 |
 y_wymiar_kolumna 
	{
	wsk_tabela= new Tabela();
	wsk_tabela->add( (Columna*) $1 );
	}
;

y_wymiar_kolumna:
 y_prosta  { $$=$1; }
 |
 y_prosta KEY DIMENSION 
	{ 
	((Columna*) $1)->setTyp(10);
	$$=$1;
	}
;




y_prosta:
IDENTIFIER IDENTIFIER   { $$= (int) new Columna((char*) $1, (char*) $2);  }
|
IDENTIFIER IDENTIFIER LEFTPARENTHESIS NUMBER RIGHTPARENTHESIS
	{
	str_rob="";
	str_rob+= (char*) $2 ;
	str_rob+= "(";
        str_rob+= (char*) $4;	
	str_rob+= ")";
	$$= (int) new Columna((char*) $1, str_rob);
	}
|
IDENTIFIER IDENTIFIER LEFTPARENTHESIS NUMBER COMMA NUMBER RIGHTPARENTHESIS
	{
	str_rob="";
	str_rob+= (char*) $2 ;
	str_rob+= "(";
	str_rob+= (char*) $4;	
	str_rob+=",";
	str_rob+= (char*) $6;	
	str_rob+= ")";
	$$= (int) new Columna((char*) $1, str_rob);
	}
;






