#pragma once

template <class T2>
class Transaction
{
	bool IsGoing;
	T2* prev; // ���������� �������� ������� ������ Cls
	T2* that; // ������� �������� ������� ������ Cls
public:
	bool IsActive() { return IsGoing; }
	Transaction(T2* ob) :prev(nullptr), that(ob), IsGoing(false) {}; // �����������

	Transaction(const Transaction & obj) : that(new T2(*(obj.that))), prev(nullptr) {};
	Transaction() {}

	~Transaction()
	{
		if (that)delete that;
		if (prev)delete prev;
	}; // ����������

	Transaction& operator=(const Transaction & obj); // ���������� ������������

	//void Show(); // ����������� �������� (����������� �
	// ��������) ������� ������ Cls
	void BeginTrans(); // ������ ����������
	void Commit(); // �����������
	void Cancel(); // ������ ����������
	void Revert();
	T2* operator->(); // ���������� ���������

};

template <class T2>
Transaction<T2>& Transaction<T2>::operator=(const Transaction<T2> & obj)
{
	if (this != &obj) // �������� �� ������ obj=obj
	{
		delete that; // �������� �������� �������� �������
		that = new T2(*(obj.that)); // �������� � �����������
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
	cout << "\n��������� �������" << endl;
	if (prev) cout << "prev = " << prev->Show() << endl;
	cout << "that =" << that->Show() << endl;
}*/

template <class T2>
void Transaction<T2>::BeginTrans()
{
	IsGoing = true;
	if (prev != nullptr)
		delete prev; // �������� ����������� ���������
	prev = that; // ������� ���������� ����������
	that = new T2(*prev); // ����� �������� �������� ��������
}

template <class T2>
void Transaction<T2>::Commit()
{
	// ��������� ������� prev, that - ����.
	IsGoing = false;
	*prev = *that;
	delete that;// �������� ���������
	that = prev;
	prev = nullptr; // ����������� ��������� ���

}

template <class T2>
void Transaction<T2>::Cancel()
{
	IsGoing = false;

	delete that; // �������� �������� ��������
	that = prev; // ���������� ���������� �������
	prev = nullptr; // ����������� ��������� ���

}

template<class T>
void Transaction<T>::Revert()
{
	if (IsGoing)
		*that = *prev;
}

