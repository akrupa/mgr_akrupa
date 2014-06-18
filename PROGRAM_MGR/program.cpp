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
}

int polecenie(string s) {  
	yy_scan_string(s.c_str());               
	yyparse();
return 0;
}

void tworz() {
  cout << "------------------ Tworzenie procesów. " << endl;
  Tworz t(w);
  t.download();
  t.create_table();
  t.insert();  
  cout << "------------------ Koniec tworzenia procesów. " << endl;
}
int program() {
	
	string line;
        string lines;	
	
   while (true) 
   {
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
   if (line.find(";") == string::npos  ) {
       lines+=line;
   } else { 
     lines+=line;  
     polecenie(lines);
     lines="";
   }
   
   if(1==a_exit) return 0; 

   if (1==a_yacc_polecenie) {
	a_yacc_polecenie=0;
	tworz();
   }
	
   } // Koniec pętli głównej programu 
	
	cout << "ERROR Program nie oczekiwanie zakończył działanie." << endl;
}


