#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "Wprowadzone.h"
#include "Tworz.h"
using namespace std;

string int2str(int a);

extern int a_exit;
extern int a_error_yacc;
extern int a_yacc_polecenie;
extern string a_yacc_string;
extern string a_yacc_string_dwa;

extern "C"
{
        int yyparse(void);
       
        int yywrap();
        int yy_scan_string(const char *);
        int yylex(void);  
}

int polecenie(string s);  
void preambula();
int program();
void tworz();
void tworz_pgloader();
void towrz_script();



