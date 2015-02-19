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
	List<double> lol;
	lol.add(1);
	List<double> ha(lol);
	for (auto i = ha.iterator(); !i.end(); ++i)
	{
		cout << *i << endl;
	}

	return 0;
}

