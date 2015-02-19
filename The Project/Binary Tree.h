

#pragma once

template<typename T>
struct BinaryNode
{
	BinaryNode(T key)
	{
		this->key = key;
		left = right = parent = NULL;
	}

	BinaryNode * left, * right, *parent;
	T key;
};


// simple binary search tree that doesn't allow duplicate keys
template<typename T>
class BinarySearchTree
{
public:

	BinarySearchTree()
	{
		root = NULL;
	}

	bool add(T elem)
	{
		if (root == NULL)
		{
			root = new BinaryNode<T>(elem);
			return true;
		}
		BinaryNode<T> * current = root;
		while (true)
		{
			if (current->key < elem)
			{
				// navigate right
				if (current->right == NULL)
				{
					current->right = new BinaryNode<T>(elem);
					current->right->parent = current;
					return true;
				}
				current = current->right;
				continue;
			}
			if (current->key > elem)
			{
				// navigate left
				if (current->left == NULL)
				{
					current->left = new BinaryNode<T>(elem);
					current->left->parent = current;
					return true;
				}
				current = current->left;
				continue;
			}
			if (current->key == elem) return false;

		}
	}

	// return true if element is found
	bool find(T elem)
	{
		if (root == NULL) return false;
		BinaryNode<T> * current = root;
		while (true)
		{
			if (current->key == elem) return true;
			if (current->key < elem)
			{
				// navigate right
				if (current->right == NULL) return false;
				current = current->right;
				continue;
			}
			if (current->key > elem)
			{
				// navigate left
				if (current->left == NULL) return false;
				current = current->left;
				continue;
			}
		}
	}

	// finds element and deletes it, returns false if no such element
	bool remove(T elem)
	{
		if (root == NULL) return false;
		BinaryNode<T> * current = root;
		while (true)
		{
			if (current->key == elem)
			{
				// no children
				if (current->left == NULL && current->right == NULL)
				{
					current->parent->left == current ?
						current->parent->left = NULL : current->parent->right = NULL;
					delete current;
					return true;
				}
				// two children
				if (current->left != NULL && current->right != NULL)
				{
					// DONE: handle two children deletion
					// find minimum in right subtree
					BinaryNode<T> * minimum = current->right;
					// if the minimum element is on the right
					// retain its right subtree
					if (minimum->left == NULL)
					{
						current->key = minimum->key;
						current->right = minimum->right;
						current->right->parent = current;
						delete minimum;
						return true;
					}
					while(minimum->left != NULL)
					{
						minimum = minimum->left;
					}
					current->key = minimum->key;
					// stop parent from pointing to deleted node
					BinaryNode<T> * parent = minimum->parent;
					parent->left = NULL;
					delete minimum;
					return true;
				}
				// one child
				BinaryNode<T> * replacement;
				// choose replacement child
				current->left == NULL ? replacement = current->right : replacement = current->left;
				current->key = replacement->key;
				current->left = replacement->left;
				current->right = replacement->right;
				if (current->left != NULL) current->left->parent = current;
				if (current->right != NULL) current->right->parent = current;
				delete replacement;
				return true;
			}
			if (current->key < elem)
			{
				// navigate right
				if (current->right == NULL) return false;
				current = current->right;
				continue;
			}
			if (current->key > elem)
			{
				// navigate left
				if (current->left == NULL) return false;
				current = current->left;
				continue;
			}
		}
	}


private:
	BinaryNode<T> * root;
};