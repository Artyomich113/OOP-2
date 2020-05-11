#pragma once

#pragma once

//#define STACK_H

#include <cassert> // assert
#include <iostream>
#include <iomanip> // setw
#include "Adapter.h"

namespace PrioriyQueueStructure
{
	template<typename T> struct data
	{
		T val;
		data<T> * next;
		data<T> * prev;
	};

	template <typename T> class PriorityQueue : public Adapter<T>
	{
		int len;
		data<T> * front;
		data<T> * rear;
	public:
		PriorityQueue();
		PriorityQueue(const PriorityQueue<T> &);
		~PriorityQueue();
		void Push(T v);
		T Top();
		T Pop();
		int Size();
		std::string name(){return "PriorityQueue"; }
	};

	template <typename T>
	PriorityQueue<T>::PriorityQueue()
	{
		front = nullptr;
		rear = nullptr;
		len = 0;
	}


	template <typename T>
	PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> & queue)
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
	PriorityQueue<T>::~PriorityQueue()
	{
		while (front)
		{
			data<T> * del = front;
			front = front->next;
			delete del;
		}
	}

	template<typename T>
	void PriorityQueue<T>::Push(T val)
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

		data<T> * p = rear;

		while (p != nullptr)
		{

			if (*val < *p->val)
			{
				data<T> * new_el = new data<T>;
				new_el->next = p;
				new_el->prev = p->prev;
				new_el->val = val;

				if (p->prev)
				{
					p->prev->next = new_el;
				}
				p->prev = new_el;
				return;
			}
			p = p->next;
		}

		data<T> * new_el = new data<T>;
		new_el->val = val;
		new_el->next = nullptr;
		new_el->prev = front;

		new_el->prev = front;
		front->next = new_el;

		front = new_el;
	}

	template<typename T>
	inline T PriorityQueue<T>::Top()
	{
		if (!front)
			return T();

		return front->val;
	}

	template<typename T>
	T PriorityQueue<T>::Pop()
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

	template <typename T>
	int PriorityQueue<T>::Size()
	{
		return len;
	}

}
