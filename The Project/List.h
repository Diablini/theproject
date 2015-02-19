

#pragma once

template<typename T>
struct ListNode
{
	ListNode();
	~ListNode();

	T data;
	ListNode * next;
};

// forward list iterator
template<typename T>
class list_iterator
{
public:
	list_iterator(ListNode<T> * start);

	// advance forward postfix and prefix
	void operator++();
	void operator++(int);
	// dereference underlying data
	T& operator*();
	
	// return true when there is no underlying element
	bool end() const;

	// return position to start of list
	void reset();

private:
	ListNode<T> * currentPos;
	ListNode<T> * startPos;
};


template<typename T>
class List
{
public:
	List();
	~List();
	List(List& c);

	void add(T element);
	void remove(size_t position);

	T& operator[](size_t position);
	list_iterator<T> iterator() const;

private:
	ListNode<T> * first;
};

// CODE STARTS HERE

template<typename T>
List<T>::List(List& c)
{
	if (c.first == NULL)
	{
		first = NULL;
		return;
	}
	first = new ListNode<T>;
	first->data = c.first->data;
	if (c.first->next == NULL) return;
	ListNode<T> * current = first;
	ListNode<T> * target = c.first;
	while(target->next != NULL)
	{
		current->next = new ListNode<T>;
		current->next->data = target->next->data;
		current = current->next;
		target = target->next;
	}
}

template<typename T>
list_iterator<T>::list_iterator(ListNode<T> * start)
{
	startPos = currentPos = start;
}

template<typename T>
ListNode<T>::~ListNode()
{
	delete next;
}

template<typename T>
ListNode<T>::ListNode()
{
	next = NULL;
}

template<typename T>
List<T>::List()
{
	first = NULL;
}

template<typename T>
List<T>::~List()
{
	delete first;
}

template<typename T>
T& List<T>::operator[](size_t pos)
{
	ListNode<T> * current = first;
	for (size_t i = 0; i < pos; i++)
	{
		current = current->next;
	}
	return current->data;
}

template<typename T>
void List<T>::add(T element)
{
	if (first == NULL)
	{
		first = new ListNode<T>;
		first->data = element;
		return;
	}
	ListNode<T> * temp = first;
	first = new ListNode<T>;
	first->data = element;
	first->next = temp;
}

template<typename T>
void List<T>::remove(size_t pos)
{
	ListNode<T> * current = first;
	for (size_t i = 0; i < pos - 1; i++)
	{
		current = current->next;
	}

	if (current->next != NULL)
	{
		ListNode<T> * temp = current->next;
		current->next = temp->next;
		temp->next = NULL;
		delete temp;
	}
}

template<typename T>
list_iterator<T> List<T>::iterator() const
{
	// DONE: actually return a valid iterator
	list_iterator<T> res(first);
	return res;
}

template<typename T>
void list_iterator<T>::operator++()
{
	currentPos = currentPos->next;
}

template<typename T>
void list_iterator<T>::operator++(int)
{
	currentPos = currentPos->next;
}

template<typename T>
void list_iterator<T>::reset()
{
	currentPos = startPos;
}

template<typename T>
bool list_iterator<T>::end() const
{
	return (currentPos == NULL);
}

template<typename T>
T& list_iterator<T>::operator*()
{
	return currentPos->data;
}
