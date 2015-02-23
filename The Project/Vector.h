

#pragma once

// TODO: fix vector

#include "exception.h"

#define VECTOR_MAX_SIZE 50000
#define VECTOR_INITIAL_SIZE 64

template <typename T>
class vector_iterator
{
public:

	vector_iterator(size_t pos, Vector * parent, T* data)
	{
		this->pos = pos;
		this->parent = parent;
		this->data = data;
	}

	bool end() const
	{
		return (pos == parent->size());
	}

	T& operator[](size_t index)
	{
		return data[index];
	}

	bool operator==(const vector_iterator& c)
	{
		return (data == c.data && pos == c.pos);
	}

	bool operator!=(const vector_iterator& c)
	{
		return (data != c.data || pos != c.pos);
	}

	T& operator*()
	{
		return data[pos];
	}

	void operator++()
	{
		if (pos + 1 <= parent->size() ) ++pos;
	}

	void operator++(int)
	{
		if (pos + 1 <= parent->size() ) ++pos;
	}

	void operator--()
	{
		if (pos != 0) --pos;
	}

	void operator--(int)
	{
		if (pos != 0) --pos;
	}

	void operator+(size_t index)
	{
		if (pos + index <= parent->size() ) pos += index;
		else pos = parent->size();
	}

	void operator-(size_t index)
	{
		if (pos >= index) pos -= index;
		else pos = 0;
	}

private:
	size_t pos;
	Vector<T> * parent;
	T * data;
};

template <typename T>
class Vector
{
	Vector()
	{
		capacity = VECTOR_INITIAL_SIZE;
		Size = 0;
		data = new T [capacity];
	}

	~Vector()
	{
		delete [] data;
	}

	T& operator[](size_t index)
	{
		return data[index];
	}

	size_t size() const {return Size;}

private:
	T* data;
	size_t Size;
	size_t capacity;

	void resizeUp()
	{
		if (capacity * 2 > VECTOR_MAX_SIZE)
			throw Base_Exception("Resizing vector oversteps maxsize",this);
		T * olddata = data;
		capacity *=2;
	}

};