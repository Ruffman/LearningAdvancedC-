// Advanced Pointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "construct" << endl;
	}

	~Test()
	{
		cout << "destruct" << endl;
	}

	void greet()
	{
		cout << "Hello" << endl;
	}
};

class Temp
{
private:
	unique_ptr<Test[]> pTest;

public:
	Temp() : pTest(new Test[2]) {}
};

int main()
{
	{ // reduce scope
		unique_ptr<Test[]> pTest(new Test[2]);
		pTest[1].greet();
	}

	//Temp temp;

	cout << "Finished" << endl;


	shared_ptr<Test> pTest2(nullptr);
	{
		shared_ptr<Test> pTest1 = make_shared<Test>();
		pTest2 = pTest1; // bc of that memory wont be freed until after program ends
	}

	cout << "shared ptr" << endl;
}
