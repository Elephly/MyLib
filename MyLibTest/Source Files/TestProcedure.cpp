#include "TestProcedure.h"

TestProcedure::TestProcedure(char *title, TestMenu *parent) : title(title), parent(parent)
{
	if (parent != 0)
	{
		parent->addMenuItem(new TestMenuItem(this));
	}
}

TestProcedure::~TestProcedure()
{
}

void TestProcedure::invoke(TestIO *view)
{
	view->displayProcedure(this);
	doProcedure(view);
	view->requestAcknowledgement();
	if (parent != 0)
	{
		parent->enter(view);
	}
}

char *TestProcedure::getTitle()
{
	return title;
}