// The Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include "Stack.h"

using std::cout;
using std::cin;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	Stack<double> lol;
	for (size_t i = 0; i < 170010; i++)
	{
		lol.push(i);
	}

	for (size_t i = 0; i < 9999; i++)
	{
		cout << lol.pop();
	}

	return 0;
}

