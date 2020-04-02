#include "pch.h"
#include "Employee.h"
#include "ChadEmployee.h"

void ChadEmployee::DevelopProduct()
{
	if (product)
	{
		(*(*product))->DoWork(step, name);
		if ((*(*(product)))->IsReady())
		{
			std::cout << (*(*(product)))->GetName() << " developed" << std::endl;
			(*product)->Commit();
		}
	}
}

ChadEmployee::ChadEmployee(float step, std::string name)
{
	this->step = step;
	this->name = name;
}




ChadEmployee::~ChadEmployee()
{
}
