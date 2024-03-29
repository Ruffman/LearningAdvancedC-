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
	int* _pBuffer{ nullptr };

public:
	Test()
	{
		_pBuffer = new int[SIZE] {};
	}

	Test(int i)
	{
		_pBuffer = new int[SIZE] {};

		for (int i = 0; i < SIZE; i++)
		{
			_pBuffer[i] = 7 * i;
		}
	}

	Test(const Test& other)
	{
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
	}

	// Move constructor
	Test(Test&& other)
	{
		cout << "move const" << endl;
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr; //else memory deleted; didn't fully understand
	}

	Test& operator=(const Test& other)
	{
		_pBuffer = new int[SIZE] {};

		memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
		return *this;
	}

	// Move assignment
	Test& operator=(Test&& other)
	{
		cout << "move assign" << endl;
		delete[] _pBuffer; // since object already exists we need to free the space
		_pBuffer = other._pBuffer;
		other._pBuffer = nullptr;

		return *this;
	}

	~Test()
	{
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

int main()
{
	vector<Test> vec;
	vec.push_back(Test());

	Test test;
	test = getTest(); // assigning rvalue

}
