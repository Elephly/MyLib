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

void TestIO::displayMessage(char *message)
{
	cout << message << endl;
	askForAcknowledgement();
}

int TestIO::askForInteger()
{
	cout << "Enter an integer: ";
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

void TestIO::askForAcknowledgement()
{
	cout << endl << "Press enter to continue.";
	requestAcknowledgement();
}

int TestIO::requestInteger()
{
	int success = 0;
	int in;
	while (success != 1)
	{
		success = scanf_s("%d", &in);
		while (getchar() != '\n');

		if (success != 1)
		{
			printf("Invalid input. Try again: ");
		}
	}
	return in;
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
	 int i = 1;
	 char *out = (char *)calloc(i, sizeof(char));
	 out[i - 1] = '\0';
	 char in;

	 do
	 {
		 in = (char)getchar();
		 if (in != '\n')
		 {
			 char *tmp = out;
			 out = (char *)calloc(++i, sizeof(char));
			 if (tmp)
			 {
				 strcpy(out, tmp);
				 free(tmp);
			 }
			 out[i - 2] = in;
			 out[i - 1] = '\0';
		 }
	 } while (in != '\n');

	 return out;
 }

 void TestIO::requestAcknowledgement()
 {
	 getchar();
 }