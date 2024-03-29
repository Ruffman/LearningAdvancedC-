// Functors.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct Test
{
	virtual bool operator()(string& text) = 0;
};

struct MatchTest : Test //Functor: struct or class overloading ()
{
	bool operator()(string& text)
	{
		return text == "lion";
	}
};

struct countTest : Test //Functor: struct or class overloading ()
{
	int testSize = 0;

	countTest(int size) : testSize(size) {}
	bool operator()(string& text)
	{
		return text.size() == 5;
	}
};

void check(string text, Test& pred)
{
	if (pred(text))
	{
		cout << "Match" << endl;
	}
	else
	{
		cout << "No Match" << endl;
	}
}

int main()
{
	MatchTest pred;
	countTest count = countTest(5);

	string val = "lion";

	check(val, pred);
	check(val, count);
}

