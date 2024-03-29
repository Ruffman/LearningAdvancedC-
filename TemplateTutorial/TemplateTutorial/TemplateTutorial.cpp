// TemplateTutorial.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>

template<class T, class K>
class Test
{
private:
	T object;
	K thing;

public:
	Test(T obj, K thing) {
		this->object = obj;
		this->thing = thing;
	}

	void print() {
		std::cout << object << thing << std::endl;
	}
};

template<typename T> //class or typename works; is not always class
void print(T t)
{
	std::cout << t << std::endl;
}

void print(std::string s)
{
	std::cout << s + " xD" << std::endl;
}

int main()
{
	Test<int, int> tests(3, 6);

	std::string s = "Hit there";

	print<int>(5);
	print(s);
	print<std::string>("Ya cunt");

	tests.print();
}