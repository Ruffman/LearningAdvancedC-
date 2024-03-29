// Binding.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

//int add(int a, int b, int c)
//{
//	cout << a << ", " << b << ", " << c << endl;
//	return a + b + c;
//}

class Test
{
public:
	int add(int a, int b, int c)
	{
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}
};

int run(function<int(int, int)> func)
{
	return func(7, 3);
}

int main()
{
	//auto calc = bind(add, _1, _2, _3); // _x are placeholders for as many arguments as the function requires
	//auto calc = bind(add, _2, _3, _1); // placeholders can change order!!
	//auto calc = bind(add, _2, 100, _1); // mix it up

	Test test;
	auto calc = bind(&Test::add, test, _2, 100, _1);


	cout << calc(4, 2) << endl;
	cout << run(calc) << endl;

}
