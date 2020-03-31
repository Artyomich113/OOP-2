#include "pch.h"
#include "Product.h"

void Product::DoWork(float step)
{
	process += step;
	std::cout <<name << " " << process << std::endl;
}

std::string Product::GetName()
{
	return name;
}

Product * Product::operator=(Product ob)
{
	//std::cout << process << " = " << ob.process << std::endl;
	this->process = ob.process;
	return this;
}

Product::Product() : process(0)
{

}

Product::Product(std::string str) : name(str), process(0)
{

}


Product::~Product()
{
}
