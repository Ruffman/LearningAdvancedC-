#pragma once

#include <iostream>

 template<typename T>
class ring
{
private:
	int _pos = 0;
	int _size = 0;
	T* _elements = nullptr;

public:
	class iterator;

	ring() = default;
	ring(int size) : _size(size) 
	{
		_elements = new T[_size];
	}
	~ring() 
	{
		delete [] _elements;
	}

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(_size, *this);
	}

	void add(T element) 
	{
		_elements[_pos++] = element;

		if (_pos == _size)
		{
			_pos = 0; 
		}
	}

	T& get(int pos) const
	{
		return _elements[pos];
	}

	int size() const { return _size; }
};

template<typename T>
class ring<T>::iterator
{
private:
	int _pos = 0;
	ring &_ring;

public:
	iterator(int pos, ring& container) : _pos(pos), _ring(container) {}

	iterator& operator++()
	{
		++_pos;
		return *this;
	}

	iterator& operator++(int) //for postfix++ needs "useless" argument
	{
		_pos++;
		return *this;
	}

	bool operator!=(const iterator& other) const
	{
		if(_pos != other._pos)
		{
			return true;
		}
		return false;
	}

	T& operator*() const
	{
		return _ring.get(_pos);
	}
};
