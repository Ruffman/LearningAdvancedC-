// Exceptions.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

////1
//void goesWrong() {
//	bool error1 = false;
//	bool error2 = true;
//
//	if (error1) {
//		throw 8;
//	}
//	if (error2) {
//		throw (double)6.5;
//	}
//}

////2
//class CanGoWrong {
//public:
//	CanGoWrong() {
//		//char *pMemory = new char[999999999];
//		//delete[] pMemory;
//		if (true) {
//			throw bad_array_new_length();
//		}
//	}
//};

////3
//class MyException : public exception {
//public:
//	virtual const char* what() const throw() {
//		return "Something bad happened!";
//	}
//};
//
//class Test {
//public:
//	void doesSomething() {
//		throw MyException();
//	}
//};

//4
void superWrong() {
	bool error1 = true;
	bool error2 = false;

	if (error1) {
		throw bad_alloc();
	}

	if (error2) {
		throw exception();
	}
}

int main()
{
	//4
	try
	{
		superWrong();
	}
	catch (exception &e) //!!!Catch subclasses first!!!
	{
		cout << "Exception: " << e.what() << endl;
	}
	catch (bad_alloc &e)
	{
		cout << "Bad_Alloc: " << e.what() << endl;
	}

	////3
	//Test test;

	//try
	//{
	//	test.doesSomething();
	//}
	//catch (MyException &e)
	//{
	//	cout << e.what() << endl;
	//}

	////2
	//try 
	//{
	//	CanGoWrong wrong;
	//}
	//catch(const exception &e)
	//{
	//	cout << e.what() << endl;
	//}

	////1
	//try
	//{
	//	goesWrong();
	//}
	//catch (int e)
	//{
	//	cout << "Error Code: " << e << endl;
	//}
	//catch (double e)
	//{
	//	cout << "Error code: " << e << endl;
	//}


    std::cout << "Hello World!\n"; 

	getchar();
	return 0;
}
