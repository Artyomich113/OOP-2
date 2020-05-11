#pragma once


template <typename T> class Adapter
{
public:
	virtual T Pop() = 0;
	virtual void Push(T v) = 0;
	virtual T Top() = 0;
	virtual std::string name() = 0;
	virtual int Size() = 0;
};