#include "pch.h"
#include "FuneralTarget.h"


bool FuneralTarget::QuantityValidate(int i)
{
	return i % 2 == 0;
}

FuneralTarget::FuneralTarget(float budget)
{
	this->budget = budget;
}


FuneralTarget::~FuneralTarget()
{
}
