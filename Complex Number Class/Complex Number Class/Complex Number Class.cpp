// Complex Number Class.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

#include "Complex.h"

using namespace std;
using namespace Ruff;

int main()
{
	Ruff::Complex c1(1.2, 2.6);
	Ruff::Complex c2(c1);
	Ruff::Complex c3 = c1 + c2;


	cout << c2 << c3 << c1+c3+c1 << c2 + 3 << 2 + c1 + c2 + c3 + 6 << *c2 << endl;

	if (c1 != c2)
	{
		cout << "not equal" << endl;
	}
	else
	{
		cout << "equal" << endl;
	}

}

