XXFLAGS =

LEX=lex
YACC = yacc -d
CC = cc 
GCC= g++

file_analiza=y.tab.c y.tab.h  lex.yy.c lex.yy.h

OBJS =   program.o main.o 	

TESTOBJS= test.o p.o testrunner.o


LIBS = 
TESTLIBS =  

TARGET=main
app: 
	$(LEX)  leksykalna.l
	$(YACC) skladniowa.y
	$(CC)  -c lex.yy.c
	$(GCC) -c program.cpp
	$(GCC) -c Tabela.cpp
	$(GCC) -c Wprowadzone.cpp
	$(GCC) -c Tworz.cpp
	$(GCC) -o main  Tabela.o   Wprowadzone.o Tworz.o program.o lex.yy.o y.tab.c main.cpp 



t:
	$(LEX)  leksykalna.l
	$(YACC) skladniowa.y
	$(CC)  -c lex.yy.c
	$(GCC) -c program.cpp
	$(GCC) -c Tabela.cpp
	$(GCC) -c Wprowadzone.cpp
	$(GCC) -c Tworz.cpp
	$(GCC) -o test Tabela.o  Wprowadzone.o Tworz.cpp program.o lex.yy.o y.tab.c test.cpp testrunner.cpp -lcppunit

clean:
	rm -f $(file_analiza)
	rm *.o  $(TARGET)
 

	
