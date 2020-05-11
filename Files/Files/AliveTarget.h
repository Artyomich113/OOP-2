#pragma once

#include "Target.h"
class AliveTarget: public Target
{
public:
	bool QuantityValidate(int);
	AliveTarget(float budget);
	~AliveTarget();
};

