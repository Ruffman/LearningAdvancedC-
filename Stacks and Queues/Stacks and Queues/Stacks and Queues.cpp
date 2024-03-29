// Stacks and Queues.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Test 
{
private:
	string _name;

public:
	Test();
	Test(string name) : _name(name) {}

	~Test()
	{
		// cout << "Object destroyed" << endl;
	}

	auto print()
	{
		cout << _name << endl;
	}
};

int main()
{
	// Last IN First OUT
	stack<Test> testStack;

	testStack.push(Test("Hello"));
	testStack.push(Test("My"));
	testStack.push(Test("Name"));

	cout << endl;

	//// This is invalid code since object is destroyed 
	//Test &test1 = testStack.top();
	//testStack.pop();
	//test1.print(); // reference refers to destroyed object!!!

	while (testStack.size() > 0)
	{
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	cout << endl;

	// First IN First OUT
	queue<Test> testQueue;

	testQueue.push(Test("Hello"));
	testQueue.push(Test("My"));
	testQueue.push(Test("Name"));

	cout << endl;

	//// This is invalid code since object is destroyed 
	//Test &test1 = testStack.top();
	//testStack.pop();
	//test1.print(); // reference refers to destroyed object!!!

	while (testQueue.size() > 0)
	{
		Test &test = testQueue.front();
		test.print();
		testQueue.pop();
	}
}
