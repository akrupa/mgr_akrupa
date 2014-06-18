#ifndef WPROWADZONE_CPP
#define WPROWADZONE_CPP

#include "Wprowadzone.h"

Wprowadzone* Wprowadzone::w=NULL;

Wprowadzone::Wprowadzone() {
  fact=new Tabela();
}


Wprowadzone* Wprowadzone::getInstance() 
{
  if (NULL==w) {
     w= new Wprowadzone();
     return w;
  } else {
   return w;
 }
}


void Wprowadzone::setSave_dir(string s) {
  this->save_dir=s;
}
string Wprowadzone::getSave_dir() {
  return this->save_dir;
}

void Wprowadzone::setName_user(string n) {
        this->name_user=n;
}

void Wprowadzone::setName_base(string n) {
        this->name_base = n;
}

string Wprowadzone::getName_user() {
                return this->name_user;
}

string Wprowadzone::getName_base() {
                return this->name_base;
}

void Wprowadzone::setFact(Tabela* s) {
         this->fact=s;
}

Tabela* Wprowadzone::getFact() {
        return this->fact; 
}

void Wprowadzone::addWymiar(Tabela* t) {
   this->tab_wymiar.push_back(t);
}

Tabela* Wprowadzone::getWymiar(string s) {
  Tabela* t=NULL;
  
   for(int i=0; tab_wymiar.size();++i) {
	if ( tab_wymiar[i]->getName_tab()==s) {
	   t = tab_wymiar[i];
	   break;
	}
   } 
  

  return t;
}

vector<Tabela*>&  Wprowadzone::getTab_wymiar() {
	return this->tab_wymiar;
}

#endif
