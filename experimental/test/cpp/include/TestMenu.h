#ifndef TESTMENU_H
#define TESTMENU_H

#include <vector>
#include "TestIO.h"
#include "TestMenuItem.h"
#include "TestProcedure.h"

#include <iostream>
using namespace std;

class TestIO;
class TestMenuItem;
class TestProcedure;

class TestMenu
{
public:
	TestMenu(char *title, TestMenu *parent = 0, TestProcedure *prerequisite = 0);
	~TestMenu();

	void enter(TestIO *view);
	void addMenuItem(TestMenuItem *item);
	void goBack(TestIO *view);

	char *getTitle();
	TestMenu *getParent();
	vector<TestMenuItem *> *getMenuItems();

private:
	char *title;
	TestMenu *parent;
	vector<TestMenuItem *> *items;
};

#endif // TESTMENU_H