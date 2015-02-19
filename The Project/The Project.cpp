// The Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include "Stack.h"
#include "Binary Tree.h"

using std::cout;
using std::cin;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	List<double> lol;
	lol.add(1);
	List<double> ha(lol);
	BinarySearchTree<int> mytree;
	mytree.add(5);
	mytree.add(6);
	mytree.add(4);
	mytree.add(3);
	mytree.add(7);
	mytree.add(9);
	mytree.add(8);
	mytree.remove(6);
	bool test = mytree.find(6);
	return 0;
}

