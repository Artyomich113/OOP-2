#include "pch.h"
#include "BudgetException.h"

BudgetException::BudgetException(float reqB, float orderP)
{
	requiredBudget = reqB;
	orderPrice = orderP;
}

BudgetException::~BudgetException()
{
	std::cout << "~BudgetException" << std::endl;
}
