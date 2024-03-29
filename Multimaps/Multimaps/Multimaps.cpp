// Multimaps.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Dude"));
	lookup.insert(make_pair(10, "Turd"));
	lookup.insert(make_pair(13, "Dick"));
	lookup.insert(make_pair(23, "Bob"));
	lookup.insert(make_pair(23, "Vicky"));


	for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	for (multimap<int, string>::iterator it = lookup.find(10); it != lookup.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}
	
	cout << endl;

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

	for (multimap<int, string>::iterator it = its.first; it != its.second; it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	auto its2 = lookup.equal_range(30);

	for (auto it = its.first; it != its.second; it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

}
