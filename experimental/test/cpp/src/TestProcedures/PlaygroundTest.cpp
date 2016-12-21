#include "PlaygroundTest.h"

#include "MyLib.h"
#include "TestMenu.h"

using namespace MyLib;

PlaygroundTest::PlaygroundTest(TestMenu *parent) : TestProcedure("Playground", parent)
{

}

PlaygroundTest::~PlaygroundTest()
{

}

void PlaygroundTest::doProcedure(TestIO *view)
{
	/*
	 * IDEAS:
	 * -MyArray
	 */

	// Begin play here...
	MyDice *d = new MyDice(6);
	for (int i = 0; i < 10; i++) cout << d->roll() << endl;
	
	MyCoin *c = new MyCoin();
	for (int i = 0; i < 10; i++) cout << c->flip() << endl;
}