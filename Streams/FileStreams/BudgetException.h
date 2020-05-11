#pragma once
class BudgetException
{
public:
	float requiredBudget;
	float orderPrice;
	BudgetException(float reqB, float orderP);
	~BudgetException();
};

