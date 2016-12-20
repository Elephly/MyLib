#ifndef STRINGTOINTTEST_H
#define STRINGTOINTTEST_H

#include "TestProcedure.h"

class StringToIntTest : public TestProcedure
{
public:
	StringToIntTest(TestMenu *parent = 0);
	~StringToIntTest();

protected:
	virtual void doProcedure(TestIO *view);

private:

};

#endif // STRINGTOINTTEST_H