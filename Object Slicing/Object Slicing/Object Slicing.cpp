// Object Slicing.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Parent
{
private:
	int one;

public:
	Parent() : one(0) {}
	Parent(const Parent& other) : one(other.one)
	{
		cout << "copy parent" << endl;
	}
	virtual void print()
	{
		cout << "Parent" << endl;
	}
};

class Child : public Parent
{
private:
	int two;

public:
	Child() : two(2) {}
	void print()
	{
		cout << "Child" << endl;
	}
};

int main()
{
	Child c1;
	Parent &p1 = c1;
	p1.print();

	Parent p2 = Child();
	p2.print();

}

