// Vectors and Memory.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	////Vectors and Memory
	//vector<int> numbers(0, 0);

	//int capacity = numbers.capacity();

	//cout << "Size: " << numbers.size() << endl;
	//cout << "Capacity: " << capacity << endl;

	//for (int i = 0; i < 10000; i++)
	//{
	//	numbers.push_back(i);

	//	if (capacity != numbers.capacity())
	//	{
	//		capacity = numbers.capacity();
	//		cout << "Capacity: " << capacity << endl;
	//	}
	//}

	//numbers.clear(); //deletes all elements but capacity stays at its biggest value!
	//numbers.resize(100); //resizes vector to 100 but is also not changing capacity!
	//numbers.reserve(100000); //reserves more capacity


	//Two dimensional vectors
	vector<vector<int>> grid(3, vector<int>(4, 7));

	grid[1].push_back(8);

	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << flush;
		}
		cout << endl;
	}
}

