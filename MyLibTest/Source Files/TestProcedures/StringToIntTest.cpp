#include "StringToIntTest.h"

StringToIntTest::StringToIntTest(TestMenu *parent) : TestProcedure("String To Int", parent)
{

}

StringToIntTest::~StringToIntTest()
{

}

void StringToIntTest::doProcedure(TestIO *view)
{
	cout << view->askForString();
}