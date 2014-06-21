%{
#include <stdio.h>
#include "y.tab.h"

char *p;
int t_nawiasy =0;
int error_lex=0;
int error_lex_nieoczekiwany=0;
%}

alpha [a-zA-Z_]
digit [0-9]
%%
"("                     {   ++t_nawiasy;    return LEFTPARENTHESIS;}
")"                     { 
                         if(--t_nawiasy <0) 
                         { 
                         printf("ERROR LEX: Brakuje nawiasu otwierającego '('\n");
                         error_lex_nieoczekiwany=2;
                         } 
                         return RIGHTPARENTHESIS;
                        }

E|e|exit|EXIT           {return EXIT;}
make|MAKE               {return MAKE;}
create|CREATE           {return CREATE;}
key|KEY                 {return KEY;}
fact|FACTi              {return FACT;}
dimension|DIMENSION     {return DIMENSION;} 
save_dir|SAVE_DIR       {return SAVE_DIR;} 
table_name|TABLE_NAME   {return TABLE_NAME;}
base_name|BASE_NAME     {return BASE_NAME; }
user_name|USER_NAME     {return USER_NAME;}
site_web|SITE_WEB       {return SITE_WEB;}
pgloader|PGLOADER       {return PGLOADER;}
"http://"[^;\ ]+        {
                        p=(char *)calloc(strlen(yytext)+1,sizeof(char));
                        strcpy(p,yytext);
                        yylval= (int) p;
                        return SITE_WEB_ADDRESS;
                        }
{digit}+                {
                        p=(char *)calloc(strlen(yytext)+1,sizeof(char));
                        strcpy(p,yytext);
                        yylval= (int) p;
                        return NUMBER;
                        }
{alpha}+(\.{alpha})?({alpha}|{digit})* 	 {
                        p=(char *)calloc(strlen(yytext)+1,sizeof(char));
                        strcpy(p,yytext);
                        yylval= (int) p;
                        return IDENTIFIER;
                        }
";"                     {return SEMICOLON;}
","                     {return COMMA;}
\n                      /* ignoruj koniec linii */;
[ \t]+                  /* ignore białe znaki */;
.			{return LEX_ERROR;} /* jakiś znak nie został obsłużony */
%%
