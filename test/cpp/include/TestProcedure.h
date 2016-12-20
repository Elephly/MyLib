#ifndef TESTPROCEDURE_H
#define TESTPROCEDURE_H

#include "TestIO.h"
#include "TestMenu.h"
#include "TestMenuItem.h"

class TestIO;
class TestMenu;
class TestMenuItem;

// Abstract class which must be implemented for each
// individual test procedure.
// In particular, only the doProcedure(TestIO *view)
// method is required to be reimplemented.
class TestProcedure
{
public:
	TestProcedure(char *title, TestMenu *parent = 0);
	~TestProcedure();

	void invoke(TestIO *view);

	char *getTitle();

protected:
	virtual void doProcedure(TestIO *view) = 0;

private:
	char *title;
	TestMenu *parent;

};

#endif // TESTPROCEDURE_H