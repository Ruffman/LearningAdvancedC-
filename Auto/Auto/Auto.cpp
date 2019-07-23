// Auto.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

template<class T, class S>
auto test(T value, S other) -> decltype(value + other)
{
	return value + other;
}

int get()
{
	return 999;
}

auto test2() -> decltype(get())
{
	return get();
}

int main()
{
	auto value = 8;
	auto text = "Test";

	cout << test2() << endl;

	auto texts = { "one", "two", "three" };

	for (auto text : texts)
	{
		cout << text << endl;
	}

}

