#include "pch.h"
#include "AliveTarget.h"


bool AliveTarget::QuantityValidate(int i)
{
	return i % 2 == 1;
}

AliveTarget::AliveTarget(float budget)
{
	this->budget = budget;
}


AliveTarget::~AliveTarget()
{
}
