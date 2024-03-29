// Set.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person
{
private: 
	string _Name;
	int _Age;
public:
	Person() : _Name("!"), _Age(-1) {}
	Person(string name, int age) : _Name(name), _Age(age) {}

	auto print_information() const
	{
		cout << _Name << " is " << _Age << " years old" << endl;
	}

	auto operator<(const Person &other) const
	{
		return _Age < other._Age;
	}
};

int main()
{
	//set<int> numbers;

	//numbers.insert(8);
	//numbers.insert(1);
	//numbers.insert(5);

	//for (auto i : numbers)
	//{
	//	cout << i << endl;
	//}

	set<Person> persons;

	persons.insert(Person("Jon", 550));
	persons.insert(Person("Don", 60));
	persons.insert(Person("Long", 40));

	for (auto p : persons)
	{
		p.print_information();
	}

}
