// Perfect Forwarding.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Test
{

};

template<typename T>
void call(T&& arg)
{
	check(forward<T>(arg)); // forward or static_cast fixes
}

void check(Test& test)
{
	cout << "lvalue" << endl;
}

void check(Test&& test)
{
	cout << "rvalue" << endl;
}

int main()
{
	Test test;

	call(Test());

}
