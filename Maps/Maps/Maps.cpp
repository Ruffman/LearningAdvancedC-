// Maps.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> ages; //map is sorted alphabetically in this case!

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vikky"] = 30;

	cout << ages["Raj"] << endl;

	cout << ages["Sue"] << endl; //adds entry automatically!!! without value. CAREFUL!

	ages.insert(pair<string, int>("Peter", 100)); //different way of adding entry
	ages.insert(make_pair("Dick", 100)); //more elegant

	if (ages.find("Vikky") != ages.end())
	{
		cout << "Found Vikky!" << endl;
	}
	else
	{
		cout << "Key not found!" << endl;
	}

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		cout << it->first << ": " << it->second << endl;
	}

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		pair<string, int> age = *it;

		cout << age.first << ": " << age.second << endl;
	}
}
