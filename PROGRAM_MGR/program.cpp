#include "program.h"



Wprowadzone *w = Wprowadzone::getInstance();


string int2str(int a) {
    ostringstream oss;
    string s;
    oss << a;
    s = oss.str();

    return s;
}


void preambula() {
	a_exit=0;
        a_error_yacc=0;
        a_yacc_string=""; 
        a_yacc_string_dwa="";
 	a_yacc_polecenie=0;
}

int polecenie(string s) {  
	yy_scan_string(s.c_str());               
	yyparse();
return 0;
}

void tworz() {
 // cout << "------------------ Tworzenie procesów. " << endl;
  Tworz t(w);
  t.create_table();
  t.insert();  
 // cout << "------------------ Koniec tworzenia procesów. " << endl;
}

void tworz_script() {
  Tworz t(w);
  t.script(a_yacc_string, a_yacc_string_dwa);
}

void tworz_pgloader() {
  Tworz t(w);
  t.pgloader(a_yacc_string);
}


int program() {
	
	string line;
        string lines;	
	
   while (true) 
   {
   preambula();
   // Warunek utworzony w przypadku, gdy przekierunkowany jest plik na standardowe wejście
      if (cin.eof())
      {
	  cout <<"koniec pliku" << endl;
	  return 0;
      }


      if (lines.empty()) {
         cout << "=> "; // Znak zachęty do wprowadzenia piwerwszej linii polecenia
      } else {
         cout << "-> "; // Znak zachęty do wprowadzenia kolejnych lini  
      }

   std::getline(std::cin,line);
   cout << line << endl; 
      if (line.find(";") == string::npos  ) {
      lines+=line;
      } else { 
      lines+=line;  
      polecenie(lines);
      lines="";
  
	 if (0==a_error_yacc) {	 
	    if (1==a_exit) return 0; 
	    if (1==a_yacc_polecenie) { tworz(); }
	    if (2==a_yacc_polecenie) { tworz_script(); }
	    if (3==a_yacc_polecenie) { tworz_pgloader(); }
         }
      }	
   } // Koniec pętli głównej programu 
	
	cout << "ERROR Program nie oczekiwanie zakończył działanie." << endl;
}


