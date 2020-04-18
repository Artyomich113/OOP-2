#include "pch.h"
#include "Flower.h"

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

std::istream & operator>>(std::istream & s, Flower & d)
{
	char c;
	char *buf = new char[50];
	s >> d.cost >> c >> c >> buf >> c;
	d.name = buf;
	delete buf;
	return s;
}

std::ostream & operator<<(std::ostream & s, Flower & d)
{
	s << d.cost << "\'-" << d.name.c_str() << '\"';
	return s;
}
