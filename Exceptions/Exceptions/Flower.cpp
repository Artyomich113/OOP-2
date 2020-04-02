#include "pch.h"
#include "Flower.h"

Flower::Flower(float cost_)
{
	if (cost_ < 0.0f)
	{
		throw cost_;
	}
	cost = cost_;
}

Flower::~Flower()
{
	std::cout << "~Flower" << std::endl;
}

float Flower::GetCost()
{
	return cost;
}
