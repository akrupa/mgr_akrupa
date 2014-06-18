#ifndef TABLE_H
#define TABLE_H

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;



using namespace std;

class Columna {
	string name;
	int typ;
	string name_type;
	string name_columna_wymiar;
	
public:	
	Columna(int typ,string name);
	Columna(string name, string name_type);
	void pokazKolumne(ostream& out);
	
	string getNameColumna();
	string getNameType();

	void setTyp(int t);
        int getTyp();

	void setNameColumnaWymiar(string s);
	string getNameColumnaWymiar();

	string getName();
	string getNameOptional();

};


class Tabela {
	vector<Columna*> tab;
        string web_site;
        string name_tab;
public:	
	~Tabela();
	void add(Columna* k);	
	void add(string name,string type);
	void pokazTab(ostream& out);
	
	vector<Columna*>& getTab();

	void setWeb_site(string s);
	string getWeb_site();	

        void setName_tab(string s);
	string getName_tab();

	string show_tab(int option=0);
	string show_tab_optional();
	string show_all_column();
	string show_all_column_optional();
	

};




#endif
