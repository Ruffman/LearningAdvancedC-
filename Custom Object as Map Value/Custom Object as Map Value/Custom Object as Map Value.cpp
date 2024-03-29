// Custom Object as Map Value.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person
{
private:
	string _name;
	int _age;

public:
	Person() : 
		_name("NoName"), _age(-1) {}
	Person(const Person &other)
	{
		_name = other._name;
		_age = other._age;
	}
	Person(string name, int age) : 
		_name(name), _age(age) {}

	void print() const
	{
		cout << _name << ": " << _age << flush;
	}

	bool operator<(const Person &other) const
	{
		if (_name == other._name)
		{
			return _age < other._age;
		}
		return _name < other._name;
	}
};

int main()
{
	map<Person, int> people;

	people[Person("Mike", 20)] = 0;
	people[Person("Mike", 25)] = 8;
	people[Person("Susan", 50)] = 3;
	people[Person("Raj", 70)] = 6;


	for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
	{
		cout << it->second << ": " << flush;
		it->first.print();
		cout << endl;
	}
}

