// Nested Template Classes.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "ring.h"
#include <string>

using namespace std;

int main()
{
	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");
	textring.add("four");
	//textring.add("five");

	// C++98
	for (ring<string>::iterator it = textring.begin(); it != textring.end(); ++it)
	{
		cout << *it << endl;
	}

	// C++11
	for (auto val : textring)
	{
		cout << val << endl;
	}


	getchar();
}

