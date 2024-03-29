// Lists.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);

	list<int>::iterator it1 = numbers.begin();
	it1++;
	numbers.insert(it1, 100);
	cout << *it1 << endl;

	list<int>::iterator it2 = numbers.begin();
	it2++;
	it2 = numbers.erase(it2); //erasing invalidates iterator so it needs to be reassigned
	cout << *it2 << endl;

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		if (*it == 2)
		{
			numbers.insert(it, 1123);
		}
		if (*it == 1)
		{
			it = numbers.erase(it); //increments iterator and so because of the increment at end of for loop skips element
			it--; //so need to decrement once
		}
	}

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << endl;
	}
}
