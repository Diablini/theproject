

#include "Stack.h"
#include <exception>

template<typename T>
Stack<T>::Stack()
{
	stack_pointer = 0;
	capacity = STACK_INITIAL_SIZE;
	data = new T [capacity];
}

template<typename T>
Stack<T>::Stack(size_t INITIAL_SIZE)
{
	if (INITIAL_SIZE > STACK_MAX_SIZE) throw std::bad_alloc; 
	stack_pointer = 0;
	capacity = INITIAL_SIZE;
	data = new T [INITIAL_SIZE];
}

template<typename T>
Stack<T>::Stack(Stack<T>& c)
{
	stack_pointer = c.stack_pointer;
	size_t counter = c.size();
	memcpy(c.data, data, sizeof(T) * counter);
}

template<typename T>
inline size_t Stack<T>::size() const
{
	return stack_pointer;
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return (stack_pointer == 0);
}

template<typename T>
inline void Stack<T>::push(T& obj)
{
	if (stack_pointer + 1 >= capacity) resizeUp();
	data[stack_pointer] = obj;
	++stack_pointer;
}

template<typename T>
T& Stack<T>::top()
{
	if (stack_pointer == 0) throw std::exception("Top() on empty stack at " + this);
	return data[stack_pointer - 1];
}

template<typename T>
inline T Stack<T>::pop()
{
	if (stack_pointer == 0) throw std::exception("Pop() on empty stack at " + this);
	--stack_pointer;
	return data[stack_pointer];
}

template<typename T>
void Stack<T>::operator=(Stack& c)
{
	stack_pointer = c.stack_pointer;
	size_t counter = c.size();
	memcpy(c.data, data, sizeof(T) * counter);
}

template<typename T>
Stack<T>& Stack<T>::operator+(T& obj)
{
	if (stack_pointer + 1 >= capacity) resizeUp();
	data[stack_pointer] = obj;
	++stack_pointer;
}

template<typename T>
void Stack<T>::resizeUp()
{
	if (capacity * 2 > STACK_MAX_SIZE) throw std::bad_alloc;
	T * temp = new T [capacity *= 2];
	memcpy(temp, data, sizeof(T) * stack_pointer);
	data = temp;
}

template<typename T>
Stack<T>::~Stack()
{
	delete [] data;
}

template<typename T>
void Stack<T>::clear()
{
	stack_pointer = 0;
}

