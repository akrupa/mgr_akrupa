
#include<iostream>
#include <cppunit/Exception.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/TestListener.h>

#include"test.h"



using namespace std;
using namespace CPPUNIT_NS;
int main(){

	cout << " wywolanie statycznej metody poltest1::suite()" << endl;

	Test *s=poltest1::suite();

	cout << " koniec wywolania statycznej metody suite() " << endl;

	//Przesylanie wynikow poprzez SynchronizedObject

//cout << "step 1" << endl;

	TestResult controller; //kontroler przesyla wyniki do listenerow

cout << "step 2" << endl;

	TestResultCollector result;

cout << "step 3" << endl;

	controller.addListener(&result); //rezultaty przekazane zostana do result

	TestRunner runner;

cout << "step 4" << endl;

	runner.addTest(s);

cout << "step 5" << endl;

	runner.run(controller);

cout << "step 6" << endl;

	//wypisywanie otrzymanych rezultatow:

	//	CompilerOutputter c(&result,std::cout);

	TextOutputter c(&result,std::cout);

cout << "step 7" << endl;

	c.write();


	cout << "END MAIN  --- testrunner.cpp  " << endl;
}

