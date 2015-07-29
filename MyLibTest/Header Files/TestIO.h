#ifndef TESTIO_H
#define TESTIO_H

#include "TestMenu.h"
#include "TestProcedure.h"

#include <iostream>
using namespace std;

class TestMenu;
class TestProcedure;

class TestIO
{
public:
	TestIO();
	~TestIO();
	
	int displayMenu(TestMenu *menu);
	void displayProcedure(TestProcedure *procedure);

	int askForInteger();
	int askForInteger(int min, int max);
	char *askForString();

	int requestInteger();
	int requestInteger(int min, int max);
	char *requestString();
	void requestAcknowledgement();

private:

};

#endif // TESTIO_H