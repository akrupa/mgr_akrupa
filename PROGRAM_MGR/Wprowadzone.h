#ifndef WPROWADZONE_H
#define WPROWADZONE_H

#include <iostream>
#include <vector>
#include <string>

#include "Tabela.h"

using namespace std;

//static int a_exit=0;



class Wprowadzone {

private:

static Wprowadzone* w;

string save_dir; 
string name_user;
string name_base;
Tabela* fact;
vector<Tabela*> tab_wymiar;

Wprowadzone();
public:

static Wprowadzone* getInstance();

void setSave_dir(string);
string getSave_dir();

void setName_user(string name);
string getName_user();

void setName_base(string name);
string getName_base();

void setFact(Tabela* name);
Tabela* getFact(); 

Tabela* getWymiar(string s);
vector<Tabela*>&  getTab_wymiar();

void addWymiar(Tabela* t);
};



#endif
