// Files.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(push, 1)
struct Person {
	char name[50];
	int age;
	double weight;
};
#pragma pack(pop)

int main()
{
	////writing
	//ofstream outFile;
	//string outFileName = "text.text";

	//outFile.open(outFileName);

	//if (outFile.is_open())
	//{
	//	for (int i = 0; i < 10; i++)
	//	{
	//		outFile << "This is line Nr.: " << i << endl;
	//	}
	//	outFile.close();
	//}
	//else
	//{
	//	cout << "Couldn't open file name: " << outFileName << endl;
	//}


	////reading
	//ifstream inFile;
	//string inFileName = "text.text";

	//inFile.open(inFileName);

	//if (inFile.is_open())
	//{
	//	string line;

	//	while (inFile)
	//	{
	//		getline(inFile, line);
	//		cout << line << endl;
	//	}
	//	inFile.close();
	//}
	//else
	//{
	//	cout << "Can't open file: " << inFileName << endl;
	//}


	////parsing
	//ifstream input;
	//string filename = "stats.txt";

	//input.open(filename);

	//if (!input.is_open())
	//{
	//	return 1;
	//}

	//while (input)
	//{
	//	string line;

	//	getline(input, line, ':');

	//	int population;
	//	input >> population;

	//	//input.get();

	//	input >> ws; // reading whitespace c++11

	//	if (!input)
	//	{
	//		break;
	//	}

	//	cout << "'" << line << "'" << "--" << "'" << population << "'" << endl;
	//}
	//input.close();


	//reading and writing binary files
	//padding of structs
	//cout << sizeof(Person) << endl;
	string filename = "test.bin";

	ofstream outFile;

	outFile.open(filename, ios::binary);

	if (!outFile.is_open())
	{
		return 1;
	}

	Person someone = {"Dick", 200, 40.5};

	outFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));

	outFile.close();


	Person someoneElse = {};

	ifstream inFile;

	inFile.open(filename, ios::binary);

	if (!inFile.is_open())
	{
		return 1;
	}

	inFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

	inFile.close();

	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;


	getchar();
	return 0;
}
