// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BudgetException.h"
#include "Flower.h"
#include "FuneralTarget.h"
#include "AliveTarget.h"
#include "Target.h"
#include "Order.h"

//���������� ������������� ���������� ������ � �������(�����������).

void term_func()
{
	std::cout << "looks like you've played with exceptions way too much\n";
	// ... cleanup tasks performed here
	// If this function does not exit, abort is called.
	exit(-1);
}

int main()
{
// ����� ������ ����� ��������� �������� ������ AliveTarget() ��� FuneralTarget()
	Target * target = new AliveTarget(100);
	//��������� ������ � ������ ����� ��������� ���������� �������
	Flower * flower1 = new Flower(10);
	Flower * flower2 = new Flower(20);
	Flower * flower3 = new Flower(130);
	Flower * flower4 = nullptr;

	try
	{
		flower4 = new Flower(-20.0f);//���������� � ������������
	}
	catch (float i)
	{
		std::cout << "constructor exception" << i << " " << (int)flower4 << std::endl;
		//�������� new �� ������ ���������
	}

	Order * order = new Order(target);
	//������� �������� ����� ��������� ���������� �������� ������
	order->PutFlower(flower1);
	order->PutFlower(flower2);
	order->PutFlower(flower3);
	
	std::set_terminate(term_func);
	try
	{
		order->CommitOrder();
		std::cout << "Order finished\n";
	}
	catch (BudgetException* e)//���������� � �������, ���� ��������� ����� ������ �������
	{
		std::cout << "budget limit exceded " << e->orderPrice << " of " << e->requiredBudget << std::endl;
		delete e;
	}
	catch (int e)
	{
		std::cout << "flowers quantity error " << e << std::endl;//���������� ���� �������� �������� ���������� ������
	}
	catch (const std::exception& e)// ������ ����������
	{
		std::cout << e.what() << std::endl;
	}
	
	delete flower1;
	delete flower2;
	delete flower3;
	delete target;
	delete order;
	system("pause");
}