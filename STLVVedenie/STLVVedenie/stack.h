#pragma once

//#define STACK_H

#include <cassert> // assert
#include <iostream>
#include <iomanip> // setw
#include "Adapter.h"

namespace StackStructure
{
	template<typename T> struct data
	{
		T val;
		data<T> * next;
	};

	template <typename T> class Stack : public Adapter<T>
	{
		int len;
		data<T> * front;
	public:
		Stack();
		Stack(const Stack<T> &);
		~Stack();

		void Push(T);
		T Pop();
		T Top();
		int Size();

		std::string name() { return "Stack"; }
	};

	template <typename T>
	Stack<T>::Stack()
	{
		front = nullptr;
		len = 0;
	}


	template <typename T>
	Stack<T>::Stack(const Stack<T> & otherStack)
	{
		data<T> * b = otherStack.front;
		while (b)
		{
			this.push(b);
			b = b->next;
		}
	}

	template <typename T>
	Stack<T>::~Stack()
	{
		while (front)
		{
			data<T> * del = front;
			front = front->next;
			delete del;
		}
	}

	template <class T> void Stack<T>::Push(T a)
	{
		len++;
		data<T> * new_el = new data<T>;
		new_el->val = a;
		if (!front)
		{
			front = new_el;
			front->next = nullptr;
		}
		else
		{
			new_el->next = front;
			front = new_el;
		}
	};


	template <typename T>
	inline T Stack<T>::Pop()
	{
		if (!len)
			return T();
		len--;
		T to_return = front->val;
		data<T>* to_del = front;
		front = front->next;
		delete to_del;
		return to_return;
	}

	template <typename T>
	inline int Stack<T>::Size()
	{
		return len;
	}

	template <typename T>
	inline T Stack<T>::Top()
	{
		if (!front)
			return T();

		return front->val;
	}
}
