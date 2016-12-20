#include "TestMenu.h"

TestMenu::TestMenu(char *title, TestMenu *parent, TestProcedure *prerequisite) : title(title), parent(parent)
{
	if (parent != 0)
	{
		if (prerequisite != 0)
		{
			parent->addMenuItem(new TestMenuItem(this, prerequisite));
		}
		else
		{
			parent->addMenuItem(new TestMenuItem(this));
		}
	}
	items = new vector<TestMenuItem *>();
}

TestMenu::~TestMenu()
{
	if (items != 0)
	{
		items->clear();
		delete items;
		items = 0;
	}
}

void TestMenu::enter(TestIO *view)
{
	int selection = view->displayMenu(this);
	if (selection == 0)
	{
		goBack(view);
	}
	else
	{
		items->at(selection - 1)->select(view);
	}
}

void TestMenu::addMenuItem(TestMenuItem *item)
{
	items->push_back(item);
}

void TestMenu::goBack(TestIO *view)
{
	if (parent != 0)
	{
		parent->enter(view);
	}
}

char *TestMenu::getTitle()
{
	return title;
}

TestMenu *TestMenu::getParent()
{
	return parent;
}

vector<TestMenuItem *> *TestMenu::getMenuItems()
{
	return items;
}