#pragma once
class Target
{
protected:
	float budget;
public:
	float GetBudget();
	virtual bool QuantityValidate(int) = 0;
	Target();
	~Target();
};

