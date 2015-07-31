#include "StringToIntTest.h"
#include "MyConvert.h"

using namespace MyLib;

StringToIntTest::StringToIntTest(TestMenu *parent) : TestProcedure("String To Int", parent)
{

}

StringToIntTest::~StringToIntTest()
{

}

void StringToIntTest::doProcedure(TestIO *view)
{
	char *string = view->askForString();
	int out;
	if (stringToInt(string, &out))
	{
		cout << "Result: " << out << endl;
	}
	else
	{
		cout << "Input string invalid." << endl;
	}
	free(string);
}