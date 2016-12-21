#ifndef TESTMENUITEM_H
#define TESTMENUITEM_H

#include "TestIO.h"
#include "TestMenu.h"
#include "TestProcedure.h"

class TestIO;
class TestMenu;
class TestProcedure;

class TestMenuItem
{
public:
	TestMenuItem();
	TestMenuItem(TestMenu *menu);
	TestMenuItem(TestProcedure *procedure);
	TestMenuItem(TestMenu *menu, TestProcedure *procedure);
	~TestMenuItem();

	void select(TestIO *view);

	char *getTitle();
private:
	TestMenu *testMenu;
	TestProcedure *testProcedure;
};

#endif // TESTMENUITEM_H