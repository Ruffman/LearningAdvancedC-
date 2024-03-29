// Function Pointer.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test(int val)
{
	cout << "Hello" << val << endl;
}

bool match(string test)
{
	return test.size() == 3;
}

bool match2(string test)
{
	return test.size() == 4;
}

int countStrings(vector<string> &texts, bool(*match)(string test))
{
	int count = 0;
	for (auto text : texts)
	{
		if (match(text))
		{
			++count;
		}
	}
	return count;
}

int main()
{
	test(5);

	void (*pTest)(int) = test;

	pTest(8);

	vector<string> texts;
	texts.push_back("one");
	texts.push_back("two");
	texts.push_back("three");
	texts.push_back("four");
	texts.push_back("five");
	texts.push_back("six");
	texts.push_back("seven");
	texts.push_back("eight");

	cout << match("one") << endl;
	cout << count_if(texts.begin(), texts.end(), match) << endl;
	cout << countStrings(texts, match2) << endl;


}