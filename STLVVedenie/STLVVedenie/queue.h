#pragma once

#pragma once

//#define STACK_H

#include <cassert> // assert
#include <iostream>
#include <iomanip> // setw
#include "Adapter.h"

namespace QueueStructure
{
	template<typename T> struct data
	{
		T val;
		data<T> * next;
		data<T> * prev;
	};

	template <typename T> class Queue : public Adapter<T>
	{
		int len;
		data<T> * front;
		data<T> * rear;
	public:
		Queue();
		Queue(const Queue<T> &);
		~Queue();
		void Push(T v);
		T Pop();
		T Top();
		T Back();
		int Size();
		std::string name() { return "Queue"; }
	};

	template <typename T>
	Queue<T>::Queue()
	{
		front = nullptr;
		rear = nullptr;
		len = 0;
	}


	template <typename T>
	Queue<T>::Queue(const Queue<T> & queue)
	{
		this->len = queue.len;
		data<T> * b = queue.front;
		while (b)
		{
			this.push(b);
			b = b->next;
		}
	}

	template <typename T>
	Queue<T>::~Queue()
	{
		while (front)
		{
			data<T> * del = front;
			front = front->next;
			delete del;
		}
	}

	template<typename T>
	void Queue<T>::Push(T val)
	{
		len++;
		if (!rear)
		{
			
			data<T> * new_el = new data<T>;
			new_el->next = nullptr;
			new_el->prev = nullptr;

			rear = front = new_el;
			new_el->val = val;
			return;
		}

		data<T> * new_el = new data<T>;
		new_el->val = val;

		new_el->next = rear;
		new_el->prev = nullptr;

		rear->prev = new_el;
		rear = new_el;
	}

	template<typename T>
	T Queue<T>::Pop()
	{
		if (!front)
			return T();

		T to_return = front->val;

		if (len > 1)
		{
			front = front->prev;
			delete front->next;
		}
		if (len == 1)
		{
			delete front;
			front = rear = nullptr;
		}

		len--;
		return to_return;
	}

	template<typename T>
	inline T Queue<T>::Top()
	{
		if (!front)
			return T();

		return front->val;
	}

	template<typename T>
	inline T Queue<T>::Back()
	{
		return rear->val;
	}

	template <typename T>
	int Queue<T>::Size()
	{
		return len;
	}

}
