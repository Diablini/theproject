

#pragma once

#define STACK_INITIAL_SIZE 32;
#define STACK_MAX_SIZE 10000;

template<typename T>
class Stack
{
public:
	Stack();
	Stack(size_t INITIAL_SIZE);
	Stack(Stack& c);
	~Stack();

	void operator=(Stack& c);
	Stack& operator+(T& rhs);

	size_t size() const;
	bool empty() const;

	void push(T& obj);
	T pop();
	T& top();
	void clear();

private:
	size_t stack_pointer;
	size_t capacity;
	T * data;

	void resizeUp();
};