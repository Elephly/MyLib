#include "TestIO.h"
#include "TestMenu.h"
#include "TestMenuItem.h"
#include "TestProcedure.h"

/* Lib Header Includes */
#include "MyLib.h"
#include "Playground.h"
/* /////////////////// */

/* Test Procedure Includes */
#include "TestProcedures.h"
/* /////////////////////// */

using namespace MyLib;
using namespace Playground;

int main(int argc, char *argv[])
{
	TestMenu *mainMenu = new TestMenu("MyLib");

	/* Features */
	TestMenu *myBitStackMenu = new TestMenu("MyBitStack", mainMenu);
	TestMenu *myConvert = new TestMenu("MyConvert", mainMenu);
	TestMenu *myMath = new TestMenu("MyMath", mainMenu);
	TestMenu *myStringOps = new TestMenu("MyStringOps", mainMenu);
	TestMenu *myVariable = new TestMenu("MyVariable", mainMenu);
	TestProcedure *playgroundTest = new PlaygroundTest(mainMenu);
	/* //////// */

	/* MyConvert Features */
	TestProcedure *myConvertStringToInt = new StringToIntTest(myConvert);
	/* ////////////////// */

	mainMenu->enter(new TestIO());

	return 0;
}