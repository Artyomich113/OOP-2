#include "pch.h"
#include "BudgetException.h"
#include "Target.h"
#include "Flower.h"
#include "Order.h"


void Order::PutFlower(Flower * flower)
{
	flowers.push_back(flower);
}

float Order::GetPrice() const
{
	float cost = 0.0f;
	for (Flower* var : flowers)
	{
		cost += var->GetCost();
	}
	return cost;
}

Order::Order(Target * target)
{
	this->target = target;
}

const std::vector<Flower*> & Order::CommitOrder() const
{
	try
	{
		if (flowers.empty())
			throw std::exception("empty order");
	}
	catch (std::exception& e)
	{
		std::cout << "first exception catch" << std::endl;
		throw;//��������������� ����������
	}

	if (!target->QuantityValidate(flowers.size()))
	{
		throw (int)flowers.size();//���� �������� �� float, �� ����� ����� ������� ����������
	}

	float price = GetPrice();
	if (price > target->GetBudget())
	{
		throw new BudgetException(target->GetBudget(), price);
	}
	return flowers;
}

Order::~Order()
{
}
