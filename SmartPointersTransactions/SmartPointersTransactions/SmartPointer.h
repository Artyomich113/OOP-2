#pragma once

template <class T>
struct Status
{
	T* ptr; // указатель на объект
	int counter; // счетчик числа ссылок на объект
};

template <typename T>
class SmartPointer
{
	Status<T> *statusPtr;

public:
	SmartPointer(T *ptr);
	SmartPointer(const SmartPointer &);
	~SmartPointer();
	SmartPointer &operator =(const SmartPointer &);
	T *operator->();
	T & operator*();
};

template<typename T>
SmartPointer<T>::SmartPointer(T *ptr)
{
	if (!ptr) statusPtr = nullptr;
	else
	{
		statusPtr = new Status<T>;
		statusPtr->ptr = ptr;
		statusPtr->counter = 1;
	}
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer &p) :statusPtr(p.statusPtr)
{
	if (statusPtr)
	{
		statusPtr->counter++;
		std::cout << "\nincreace of pointers: count " << statusPtr->counter;
	}
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
	if (statusPtr)
	{
		statusPtr->counter--;
		std::cout << "\nobject dectructor: count " << statusPtr->counter;
		if (statusPtr->counter <= 0)
		{// ошибка
			std::cout << "\ndeleted ";
			delete statusPtr->ptr;
			delete statusPtr;
		}
	}
}

template <typename T>
T* SmartPointer<T>::operator->()
{
	if (statusPtr)
		return statusPtr->ptr;
	else
	{
		return nullptr;
	}
}

template <typename T>
T&SmartPointer<T>::operator*()
{
	if (statusPtr)
	{
		//std::cout << "ptr" << std::endl;
		return *statusPtr->ptr;
	}
	else
		return *(new T());
}

template <typename T>
SmartPointer<T>&SmartPointer<T>::operator=(const SmartPointer &p)
{
	if (statusPtr)
	{
		statusPtr->counter--;
		std::cout << "object is referencec to another object: count" << statusPtr->counter;
		if (statusPtr->counter <= 0)
		{
			delete statusPtr->ptr;
		}
	}
	statusPtr = p.statusPtr;
	if (statusPtr)
		statusPtr->counter++;
	return *this;
}
