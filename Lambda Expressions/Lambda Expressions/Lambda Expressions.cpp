// Lambda Expressions.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void test(void (*pFunc)()) 
{
	pFunc();
}

void testGreet(void(*pFunc)(string))
{
	pFunc("Bob");
}

void runDivide(double(*pFunc)(double, double))
{
	auto val = pFunc(9 , 3);
	cout << val << endl;
}

class Test
{
private:
	int _one{ 1 };
	int _two{ 2 };

public:
	void run()
	{
		int three{ 3 };
		int four{ 4 };

		auto pLambda = [this, three, four]() 
		{ 
			_one = 6;
			cout << _one << ", " << _two << endl; // Captured with this as references
			cout << three << ", " << four << endl; 
		};
		pLambda();
	}
};

int main()
{
	auto func = []() {cout << "muh d" << endl; };
	test(func);

	auto  pGreet = [](string name) { cout << "Hello " << name << endl; };
	pGreet("Mike");
	testGreet(pGreet);

	auto pDivide = [](double a, double b) -> double
	{
		if (b == 0)
		{
			return 0;
		}
		return a / b;
	};

	cout << pDivide(4.4, 2.2) << endl;
	cout << pDivide(4.4, 0.0) << endl;
	runDivide(pDivide);

	int one{ 1 };
	int two{ 2 };
	int three{ 3 };

	// Capture one and two by value
	[one, two]() { cout << one << ", " << two << endl; }();

	// Capture all local variables by value
	[=]() { cout << one << ", " << two << endl; }();

	// Capture all local variables by value but three by reference
	[=, &three]() { three = 7; cout << one << ", " << two << endl; }();
	cout << three << endl;

	// Capture all local variables by reference
	[&]() { two = 8; cout << one << ", " << two << endl; }();

	// Capture all local variables by reference but two and three by value
	[&, two, three]() { /*two = 8;*/ cout << one << ", " << two << endl; }();

	Test test;
	test.run();

	[one]() mutable { one = 2; cout << one << ", " << endl; }(); //mutable allows changing the variable even though its captured by value

}
