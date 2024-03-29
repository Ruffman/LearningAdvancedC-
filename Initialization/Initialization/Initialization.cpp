// Initialization.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class Test
{
private:
	int _id{ 3 };
	string _name{ "Mike" };

public:
	Test() = default; //default constuctor in C++11
	Test(const Test& other) = default; //default copy constructor
	//Test(const Test& other) = delete; 

	Test(int id): _id(id) {}
	Test(initializer_list<string> texts) 
	{
		for (auto text : texts)
		{
			cout << text << endl;
		}
	}

	void print(initializer_list<string> texts)
	{
		for (auto text : texts)
		{
			cout << text << endl;
		}
	}

	void printMember()
	{
		cout << _id << ": " << _name << endl;
	}

	//Test& operator=(const Test& other) = default //makes it obvious we are using default implementation of assignment
	Test& operator=(const Test& other) = delete; //Object can't be asigned: test1 = test2 won't work

};

int main()
{
	////C++ 98 initializations
	//int values[] = { 1, 4, 5 };

	//struct S {
	//	string text;
	//	int id;
	//};

	//S s1 = {"Hello", 7};

	//cout << s1.text << s1.id << endl;

	//struct {
	//	string text;
	//	int id;
	//} r1, r2 = {"Bye", 2 };

	//r1 = { "Hello", 8 };

	//cout << r1.text << r1.id << endl;
	//cout << r2.text << r2.id << endl;

	//vector<string> strings;

	//strings.push_back("One");
	//strings.push_back("Two");
	//strings.push_back("Three");

	//C++11
	int value{ 5 };
	cout << value << endl;

	string text{ "Hello" };
	cout << text << endl;

	int numbers[]{ 1,2,3 };
	cout << numbers[1] << endl;

	int* pInt = new int[3] {1, 2, 3};
	cout << pInt[2] << endl;
	delete pInt;

	int value1{};
	cout << value1 << endl;

	int* pSomething{ &value };
	cout << *pSomething << endl;

	int* pSomething2{}; // int* pSomething2{nullptr} / int* pSomething = nullptr
	cout << pSomething2 << endl;

	int numbers1[5]{}; // 5 elements of value 0
	cout << numbers1[1] << endl;

	struct {
		int value = 7;
		string text;
	} s1{5, "Hi"}, s2;

	cout << s1.text << endl;
	cout << s2.value << endl;

	vector<string> strings{ "one", "two", "six" };
	cout << strings[2] << endl;

	//Initializer list
	Test test{ "apple", "orange", "person", "something" };
	test.print({ "one", "two", "ssaasda", "four" });

	//Default init
	test.printMember();

	Test test2(22);
	test2.printMember();
}