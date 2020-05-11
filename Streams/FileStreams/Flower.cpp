#include "pch.h"
#include "Flower.h"
#include "Input.h"

Flower::Flower(float cost_, std::string name)
{
	this->name = name;
	if (cost_ < 0.0f)
	{
		throw cost_;
	}
	cost = cost_;
}

Flower::Flower(float cost_)
{
	if (cost_ < 0.0f)
	{
		throw cost_;
	}
	cost = cost_;
}

Flower::Flower()
{
	cost = 0;
	name = "";
}

Flower::~Flower()
{
	std::cout << "~Flower" << std::endl;
}

float Flower::GetCost()
{
	return cost;
}

std::istream & operator>>(std::istream & stream, Flower & flower)//controll input
{
	
	_inputString("name", flower.name,true);
	_input("cost", flower.cost);
	return stream;
}

std::ostream & operator<<(std::ostream & stream, Flower & flower)
{
	stream << flower.name << " " << flower.cost;
	return stream;
}
