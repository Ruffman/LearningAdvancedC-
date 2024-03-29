// Standard Function Type.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

bool check(string& text) 
{
	return text.size() == 3;
}

class check
{
public:
	bool operator()(string& text) { return text.size() == 5; }
} check1;

void run(function<bool(string&)> check)
{
	string test = "stars";
	cout << check(test) << endl;
}

int main()
{
	int size{ 5 };
	vector<string> vec{ "one", "two", "three" };

	auto lambda = [size](string test) { return test.size() == size; };

	int count1 = count_if(vec.begin(), vec.end(), lambda);
	cout << count1 << endl;

	bool (*pFunc)(string& text) = check;
	int count2 = count_if(vec.begin(), vec.end(), pFunc);
	cout << count2 << endl;

	int count3 = count_if(vec.begin(), vec.end(), check1);
	cout << count3 << endl;

	run(lambda);
	run(check1);
	run(check);

	function<int(int, int)> add = [](int one, int two) { return one + two; };
	cout << add(2, 6) << endl;
}
