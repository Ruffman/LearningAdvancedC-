// Sorting Vectors Deque and Friend.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Test 
{
private:
	int _id;
	string _name;

public:
	Test(int id, string name) : _id(id), _name(name) {}

	void print() const
	{
		cout << _id << ": " << _name << endl;
	}

	//auto operator<(const Test& other) const
	//{
	//	return _id < other._id;
	//}

	friend bool comp(const Test& a, const Test& b);
};

bool comp(const Test& a, const Test& b)
{
	return a._name < b._name;
}

int main()
{
	vector<Test> testObjects;

	testObjects.push_back(Test(5, "Mike"));
	testObjects.push_back(Test(10, "Sue"));
	testObjects.push_back(Test(3, "Raj"));
	testObjects.push_back(Test(7, "Vicky"));

	sort(testObjects.begin(), testObjects.end(), comp);

	for (auto i : testObjects)
	{
		i.print();
	}


}

