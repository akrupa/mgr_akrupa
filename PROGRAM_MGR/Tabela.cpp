#ifndef WPROWADZANIE_CPP
#define WPROWADZANIE_CPP

#include "Tabela.h"



Columna::Columna(string name, string name_type) {
	this->name_type= name_type;
	this->name=name;
	this->typ=0;
        this->name_columna_wymiar="";
}


string Columna::getNameColumna() {
	return this->name;
}
string Columna::getNameType() {
	return this->name_type;
}

void Columna::setTyp(int t) {
	 this->typ=t;
}
int Columna::getTyp() {
 	return this->typ;
}

void Columna::setNameColumnaWymiar(string s) {
    this->name_columna_wymiar=s;
}
string Columna::getNameColumnaWymiar() {
    return this->name_columna_wymiar;
}


void Columna::pokazKolumne(ostream& out) {
	out << this->name << " " << this->name_type;
}


Tabela::~Tabela() {
	while (!this->tab.empty()) {
	       delete   (*this->tab.begin());
	       this->tab.erase(tab.begin());
	}
}



string Columna::getName() {
	return  this->name+" "+this->name_type;
}

string Columna::getNameOptional() {
  string s="";
       
  if (2==typ) {
    s=  "id_"+ name_columna_wymiar  + " integer";
  } else {
   s =  getName();
 }
  return s;
}

vector<Columna*>& Tabela::getTab() {
		return this->tab;
}

void Tabela::add(Columna* k) {
	this->tab.insert(tab.begin(),k);
}

void Tabela::add(string name ,string type ) {
	add(new Columna(name, type));
}


void Tabela::pokazTab(ostream& out) {
	for (vector<Columna*>::iterator it= this->tab.begin(); it != this->tab.end(); ++it) {
		(*it)->pokazKolumne(out);
		out << endl;
	}
	
}


void Tabela::setWeb_site(string s) {
	this->web_site=s;
}
string Tabela::getWeb_site() {
	return this->web_site; 
}



void Tabela::setName_tab(string s) {
 	this->name_tab=s;
}

string Tabela::getName_tab() {
	return this->name_tab; 
}

/////////////////////////////////////////////////
//  Metody do pokazywanie zawartości tabeli
////////////////////////////////////////////////


string  Tabela::show_tab(int option) {
  string s="";
	for (vector<Columna*>::iterator it= this->tab.begin(); it != this->tab.end(); ++it) {
	    if (it==tab.begin()) {
		s+="  ";
	    } else {
		s+=", ";
	    }
	    if (option ==1) {
	    s+=(*it)->getNameOptional();
	    } else { 
	    s+=(*it)->getName();
            }
	s+="\n";
	}
return s;	
}
#endif

