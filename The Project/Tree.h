

#pragma once
#include "List.h"

// TODO: complete

template<typename T>
struct TreeNode
{
	T data;
	List<TreeNode *> children;
};

template<typename T>
class Tree
{

private:
	TreeNode * root;
};
