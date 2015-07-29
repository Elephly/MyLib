#ifndef PLAYGROUNDTEST_H
#define PLAYGROUNDTEST_H

#include "TestProcedure.h"

#include "Playground.h"

using namespace Playground;

class PlaygroundTest : public TestProcedure
{
public:
	PlaygroundTest(TestMenu *parent = 0);
	~PlaygroundTest();

protected:
	virtual void doProcedure(TestIO *view);

private:

};

#endif // PLAYGROUNDTEST_H