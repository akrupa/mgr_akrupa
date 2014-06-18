#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <cppunit/extensions/TypeInfoHelper.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include"test.h"

#include <iostream>

using namespace std;

void poltest1::setUp(){
 w =  Wprowadzone::getInstance();  
}

void poltest1::tearDown(){
}

void poltest1::testExit() {
     CPPUNIT_ASSERT(0==a_exit);
          polecenie("exit;  ");
     CPPUNIT_ASSERT(1==a_exit);
     CPPUNIT_ASSERT(0==a_error_yacc);
          a_exit=0;
          polecenie(" EXIT  ;");
     CPPUNIT_ASSERT(1==a_exit);
     CPPUNIT_ASSERT(0==a_error_yacc);
          a_exit=0;
          polecenie("e; ");
     CPPUNIT_ASSERT(1==a_exit);
     CPPUNIT_ASSERT(0==a_error_yacc);
          a_exit=0;
          polecenie(" E ; ");
     CPPUNIT_ASSERT(1==a_exit);
     CPPUNIT_ASSERT(0==a_error_yacc);
}
void poltest1::testName_base() {
     polecenie("base_name dwh;");
     CPPUNIT_ASSERT(0==a_error_yacc);
     CPPUNIT_ASSERT_MESSAGE( w->getName_base(), w->getName_base()=="dwh");
     polecenie("user_name etl;");
     CPPUNIT_ASSERT(0==a_error_yacc);
     CPPUNIT_ASSERT_MESSAGE(w->getName_user(),  w->getName_user()=="etl") ;
     CPPUNIT_ASSERT(0==a_error_yacc);
}

void poltest1::testFact_web_site() {
     polecenie("fact site_web http://bossa.pl/pub/ciagle/mstock/sesjacgl/sesjacgl.prn;");
     CPPUNIT_ASSERT(0==a_error_yacc);
     polecenie("fact site_web http://i ;");
     CPPUNIT_ASSERT(0==a_error_yacc);

     polecenie("fact site_web http://bossa.pl/pub/ciagle/mstock/sesjacgl/sesjacgl.prn;");
     CPPUNIT_ASSERT_MESSAGE( w->getFact()->getWeb_site(),  w->getFact()->getWeb_site()=="http://bossa.pl/pub/ciagle/mstock/sesjacgl/sesjacgl.prn") ;
     CPPUNIT_ASSERT(0==a_error_yacc);
}

void poltest1::testFact_table() {
     string line="";
     line +=" create fact gpw ( ";
     line+="  nazwa varchar(50) dimension npw ";
     line+=", data_notowania date key";
     line+=", otwarcie decimal(20, 2)";
     line+=", max decimal(20, 2)";
     line+=", min decimal(20, 2)";
     line+=", zamkniecie decimal(20, 2)";
     line+=", wartosc decimal(20,3)    ";
     line +="); ";
//     polecenie(line);
     cout << line << endl;
     CPPUNIT_ASSERT(0==a_error_yacc);
     w->getFact()->pokazTab(cout);
}

void poltest1::testDimension_table() {

     CPPUNIT_ASSERT(0==a_error_yacc);
     string line="";
     line +=" create dimension npw ( ";
     line+="  data_od timestamp ";
     line+=", data_od timestamp  ";
     line+=", nazwa  varchar(50) ";
     line+=", opis   varchar(200) ";
     line +="); ";
     polecenie(line);
     Tabela* t =  w->getWymiar("npw");
     CPPUNIT_ASSERT(NULL != t  );
     CPPUNIT_ASSERT(0==a_error_yacc);
     CPPUNIT_ASSERT_MESSAGE( t->getName_tab() ,  "npw"==t->getName_tab()) ;
     t->pokazTab(cout);
}
//Tworzenie mapy z hierarchia testow
CPPUNIT_REGISTRY_ADD( "pol1", "pol" );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( poltest1, "pol1" );




