

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

	bool add(T elem)
	{
		if (root == NULL)
		{
			root = new BinaryNode(elem);
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
					current->right = new BinaryNode(elem);
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
					current->left = new BinaryNode(elem);
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
					delete current->parent;
					return true;
				}
				// two children
				if (current->left != NULL && current->right != NULL)
				{
					// TODO: handle two children deletion;
					return true;
				}
				// one child
				BinaryNode<T> * replacement;
				// choose replacement child
				current->left == NULL ? replacement = current->right : replacement = current->left;
				current->key = replacement->key;
				delete replacement;
				current->left = current->right = NULL;
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
	BinaryNode root;
};