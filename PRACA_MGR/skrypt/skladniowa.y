%token EXIT  SAVE_DIR TABLE_NAME BASE_NAME USER_NAME
%token MAKE  NUMBER IDENTIFIER 
%token CREATE KEY FACT DIMENSION SITE_WEB SITE_WEB_ADDRESS PGLOADER
%token  LEFTPARENTHESIS RIGHTPARENTHESIS  SEMICOLON COMMA  LEX_ERROR 

%%

// Polecenie ze średnikiem
y_polecenie_srednik:
  y_polecenie SEMICOLON
;

// polecenie bez średnika
y_polecenie:
  EXIT  // wyjście z programu
  |
  MAKE  // tworzyenie sqryptów sql'owy 
  |
  SAVE_DIR IDENTIFIER  // ustawienie katalogu do zapisu 
  |
  USER_NAME IDENTIFIER	// ustawia nazwę  użytkownika bazy danych
  |
  BASE_NAME IDENTIFIER	//  ustawia nazwę bazy danych
  |
  SITE_WEB SITE_WEB_ADDRESS IDENTIFIER  // tworzy skrypt pobierające dane 
  |
  PGLOADER IDENTIFIER  // tworzenie scryptu pgloadera
  | 
  y_fakt_polecenie   // symbol nieterminalny do tworzenia tablicy faktowej
  |
  y_wymiar_polecenie // symbol nieterminalny do tworzenia tablicy wymiarów
;

y_fakt_polecenie:
  CREATE FACT IDENTIFIER LEFTPARENTHESIS y_list_fact_kolumn RIGHTPARENTHESIS
;

y_list_fact_kolumn:
 y_fact_kolumna COMMA y_list_fact_kolumn 
 |
 y_fact_kolumna 
;


y_fact_kolumna:
 y_prosta  
|
 y_prosta KEY 
|
 y_prosta DIMENSION IDENTIFIER
;

y_wymiar_polecenie:
  CREATE DIMENSION IDENTIFIER LEFTPARENTHESIS y_list_wymiar_kolumn RIGHTPARENTHESIS 
;

y_list_wymiar_kolumn:
 y_wymiar_kolumna COMMA y_list_wymiar_kolumn 
 |
 y_wymiar_kolumna 
;

y_wymiar_kolumna:
 y_prosta  
 |
 y_prosta KEY DIMENSION 
;

y_prosta:
IDENTIFIER IDENTIFIER   
|
IDENTIFIER IDENTIFIER LEFTPARENTHESIS NUMBER RIGHTPARENTHESIS
|
IDENTIFIER IDENTIFIER LEFTPARENTHESIS NUMBER COMMA NUMBER RIGHTPARENTHESIS
;

