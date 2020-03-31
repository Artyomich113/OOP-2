#pragma once

template <class T2>
class Transaction
{
	bool IsGoing;
	T2* prev; // предыдущее значение объекта класса Cls
	T2* that; // текущее значение объекта класса Cls
public:
	bool IsActive() { return IsGoing; }
	Transaction(T2* ob) :prev(nullptr), that(ob), IsGoing(false) {}; // конструктор

	Transaction(const Transaction & obj) : that(new T2(*(obj.that))), prev(nullptr) {};
	Transaction() {}

	~Transaction()
	{
		if (that)delete that;
		if (prev)delete prev;
	}; // деструктор

	Transaction& operator=(const Transaction & obj); // перегрузка присваивания

	//void Show(); // отображение значений (предыдущего и
	// текущего) объекта класса Cls
	void BeginTrans(); // начало транзакции
	void Commit(); // закрепление
	void Cancel(); // отмена транзакции
	void Revert();
	T2* operator->(); // реализация указателя

};

template <class T2>
Transaction<T2>& Transaction<T2>::operator=(const Transaction<T2> & obj)
{
	if (this != &obj) // проверка на случай obj=obj
	{
		delete that; // удаление текущего значения объекта
		that = new T2(*(obj.that)); // создание и копирование
	}
	return *this;
}

template <class T2>
T2* Transaction<T2>::operator->()
{
	return that;
}

/*template <class T2>
void Tran<T2>::Show()
{
	cout << "\nсостояния объекта" << endl;
	if (prev) cout << "prev = " << prev->Show() << endl;
	cout << "that =" << that->Show() << endl;
}*/

template <class T2>
void Transaction<T2>::BeginTrans()
{
	IsGoing = true;
	if (prev != nullptr)
		delete prev; // удаление предыдущего состояния
	prev = that; // текущее становится предыдущим
	that = new T2(*prev); // новое значение текущего значения
}

template <class T2>
void Transaction<T2>::Commit()
{
	// указатель видимый prev, that - свой.
	IsGoing = false;
	*prev = *that;
	delete that;// удаление состояния
	that = prev;
	prev = nullptr; // предыдущего состояния нет

}

template <class T2>
void Transaction<T2>::Cancel()
{
	IsGoing = false;

	delete that; // удаление текущего значения
	that = prev; // предыдущее становится текущим
	prev = nullptr; // предыдущего состояния нет

}

template<class T>
void Transaction<T>::Revert()
{
	if (IsGoing)
		*that = *prev;
}

