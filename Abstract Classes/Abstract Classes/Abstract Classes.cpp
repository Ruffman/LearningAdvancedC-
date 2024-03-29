// Abstract Classes.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Animal 
{
public:
	virtual void run() = 0;
	virtual void speak() = 0;
};

class Dog: public Animal
{
public:
	virtual void speak()
	{
		cout << "Woof!" << endl;
	}
};

class Labrador : public Dog
{
public:
	Labrador()
	{
		cout << "new labrador" << endl;
	}
	virtual void run()
	{
		cout << "Labrador is running!" << endl;
	}
};

void test(Animal &a)
{
	a.run();
}

int main()
{
	Labrador dog;
	dog.speak();
	dog.run();

	Animal *animals[5];
	animals[0] = &dog;

	animals[0]->speak();

	test(dog);

}

