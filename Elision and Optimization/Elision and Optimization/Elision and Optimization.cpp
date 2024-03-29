// Elision and Optimization.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test 
{
private:
	static const int SIZE = 100;
	int* _pBuffer = nullptr;

public:
	Test()
	{
		cout << "constructor" << endl;
		_pBuffer = new int[SIZE] {};
	}

	Test(int i)
	{
		cout << "parameterized constructor" << endl;
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++)
		{
			_pBuffer[i] = 7 * i;
		}
	}

	Test(const Test& other)
	{
		cout << "copy constructor" << endl;

		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	Test& operator=(const Test& other)
	{
		cout << "assignment" << endl;

		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	~Test() 
	{
		cout << "destructor" << endl;
		delete[] _pBuffer;
	}

	friend ostream& operator<<(ostream& out, const Test& object);
};

ostream& operator<<(ostream& out, const Test& object)
{
	out << object.SIZE;
	return out;
}

Test getTest()
{
	return Test();
}

void check(const Test& value)
{
	cout << "lvalue function" << endl;
}

void check(const Test&& value)
{
	cout << "rvalue function" << endl;
}

int main()
{
	Test lTest1 = getTest();

	cout << lTest1 << endl;

	vector<Test> vec;
	vec.push_back(Test());



	//// Rvalue and Lvalue examples
	//int value = 7;

	//int *pValue1 = &value;
	////int *pValue2 = &7; // can't work bc rvalue

	//Test *pTest1 = &test1;
	//Test *pTest2 = &getTest();

	//int *pValue3 = &++value; // refers now to 8
	//cout << *pValue3 << endl;

	////int *pValue3 = &value++; // Error because temporary rvalue
	////int *s = &(7 + value1); // (7 + value1) is an rvalue even though value1 is lvalue

	Test& rTest1 = lTest1;
	// Test& rTest2 = getTest();
	const Test& rTest2 = getTest();
	


	// RValues
	Test test3 = getTest();

	//Test &&rtest1 = test3;
	Test &&rtest1 = getTest(); // <----RVALUE

	check(test3);
	check(getTest());
	check(Test());
}
