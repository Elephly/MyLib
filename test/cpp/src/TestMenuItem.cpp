#include "TestMenuItem.h"

TestMenuItem::TestMenuItem()
{
	testMenu = 0;
	testProcedure = 0;
}

TestMenuItem::TestMenuItem(TestMenu *menu) : testMenu(menu)
{
	testProcedure = 0;
}

TestMenuItem::TestMenuItem(TestProcedure *procedure) : testProcedure(procedure)
{
	testMenu = 0;
}

TestMenuItem::TestMenuItem(TestMenu *menu, TestProcedure *procedure) : testMenu(menu), testProcedure(procedure)
{

}

TestMenuItem::~TestMenuItem()
{
	if (testMenu != 0)
	{
		delete testMenu;
		testMenu = 0;
	}
	if (testProcedure != 0)
	{
		delete testProcedure;
		testProcedure = 0;
	}
}

void TestMenuItem::select(TestIO *view)
{
	if (testProcedure != 0)
	{
		testProcedure->invoke(view);
	}
	if (testMenu != 0)
	{
		testMenu->enter(view);
	}
}

char *TestMenuItem::getTitle()
{
	if (testMenu != 0)
	{
		return testMenu->getTitle();
	}
	else if (testProcedure != 0)
	{
		return testProcedure->getTitle();
	}
	else
	{
		return "NULL";
	}
}