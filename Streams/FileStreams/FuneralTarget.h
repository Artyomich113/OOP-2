#pragma once

#include "Target.h"
class FuneralTarget: public Target
{
public:
	bool QuantityValidate(int);
	FuneralTarget(float budget);
	~FuneralTarget();
};

