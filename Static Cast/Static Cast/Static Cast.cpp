// Static Cast.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Parent
{
public:
	virtual ~Parent() {}
};

class Brother : public Parent
{

};

class Sister : public Parent
{

};

int main()
{
	Parent parent;
	Brother brother;
	Sister sister;

	float value = 3.23;
	cout << static_cast<int>(value) << endl;

	//Brother *pb = static_cast<Brother*>(&parent); // unsafe

	Parent *ppb = &brother;
	Brother *pbb = static_cast<Brother*>(ppb); // DANGER

	pbb = dynamic_cast<Brother*>(ppb); // pbb will be nullptr unless ppb is of type object!

	cout << pbb << endl;


	Sister *psb = reinterpret_cast<Sister*>(ppb); // even more unsafe than static_cast!!!

	cout << psb << endl;
    
}

