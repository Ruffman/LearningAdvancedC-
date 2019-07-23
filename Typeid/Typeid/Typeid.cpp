// Typeid.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <typeinfo> //important

int main()
{
	std::string val = "Hi";

	decltype(val) name = "Bob";

	std::cout << typeid(val).name() << std::endl;

	std::cout << name << std::endl;
}

 