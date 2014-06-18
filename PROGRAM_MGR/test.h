#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Wprowadzone.h"
#include "program.h"

class poltest1 : public CPPUNIT_NS::TestFixture{
	Wprowadzone  *w;
public:
	void setUp();
	void tearDown(); 

	void testExit();	
        void testName_base();
	void testFact_web_site();	

        void testFact_table();        
	void testDimension_table();


	CPPUNIT_TEST_SUITE(poltest1);
        CPPUNIT_TEST(testExit);
        CPPUNIT_TEST(testName_base);
	CPPUNIT_TEST(testFact_web_site);       
	CPPUNIT_TEST(testFact_table);
	CPPUNIT_TEST(testDimension_table);
	CPPUNIT_TEST_SUITE_END();

};

#endif 
