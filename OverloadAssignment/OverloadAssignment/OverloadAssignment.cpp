// OverloadAssignment.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
	int _id;
	string _name;

public:
	Test() : _id(0), _name("") {}
	Test(int id, string name) : _id(id), _name(name) {}
	~Test() // Rule of 3
	{
		cout << "Destructor running" << endl;

	}

	void print()
	{
		cout << _id << ": " << _name << endl;
	}

	Test(const Test& other) // Rule of 3
	{
		cout << "Copy constructor running" << endl;

		_id = other._id;
		_name = other._name;
	}

	const Test& operator=(const Test& other) // Rule of 3
	{
		cout << "Assignment running" << endl;

		_id = other._id;
		_name = other._name;

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Test& object)
	{
		out << object._name << ": " << object._id << endl;
		return out;
	}
};

int main()
{
	//// Copy and Asignment
	//Test test1(10, "Mike");
	//test1.print();

	//Test test2(20, "Bob");

	//test2 = test1;
	//test2.print();

	//Test test3;
	//test3 = test2;
	//test3.print();

	//cout << endl;

	//// copy initialization doesn't use assignment operator but copy constructor!
	//Test test4 = test1;
	//test4.print();

	// Overloading Left Bit Shift
	Test test1(10, "Mike");

	cout << test1 << endl;
}
