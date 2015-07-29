#include "TestIO.h"

#include <stack>

TestIO::TestIO()
{

}

TestIO::~TestIO()
{

}

int TestIO::displayMenu(TestMenu *menu)
{
	system("cls");

	stack<TestMenu *> *parentStack = new stack<TestMenu *>();
	TestMenu *p = menu->getParent();

	while (p != 0)
	{
		parentStack->push(p);
		p = p->getParent();
	}

	while (!parentStack->empty())
	{
		cout << parentStack->top()->getTitle() << "->";
		parentStack->pop();
	}

	delete parentStack;

	cout << menu->getTitle() << endl;

	int i = 1;
	for (vector<TestMenuItem *>::iterator it = menu->getMenuItems()->begin(); it != menu->getMenuItems()->end(); ++it)
	{
		cout << "\t(" << i++ << ") " << (*it)->getTitle() << endl;
	}

	if (menu->getParent() != 0)
	{
		cout << "\t(0) Back" << endl;
	}
	else
	{
		cout << "\t(0) Quit" << endl;
	}

	cout << endl<< "Select: ";

	return requestInteger(0, menu->getMenuItems()->size());
}

void TestIO::displayProcedure(TestProcedure *procedure)
{
	cout << procedure->getTitle() << endl;
}

int TestIO::askForInteger()
{
	return requestInteger();
}

int TestIO::askForInteger(int min, int max)
{
	cout << "Enter an integer between " << min << " and " << max << ": ";
	return requestInteger(min, max);
}

char *TestIO::askForString()
{
	cout << "Enter a string: ";
	return requestString();
}

int TestIO::requestInteger()
{
	return 0;
}

int TestIO::requestInteger(int min, int max)
{
	int in = min - 1;
	while (in < min || in > max)
	{
		scanf_s("%d", &in);
		while (getchar() != '\n');
		if (in < min || in > max)
		{
			printf("Invalid input. Try again: ");
		}
	}
	return in;
}

 char *TestIO::requestString()
 {
	 char *in = "";
	 scanf_s("%s", &in);
	 return in;
 }

 void TestIO::requestAcknowledgement()
 {
	 getchar();
 }