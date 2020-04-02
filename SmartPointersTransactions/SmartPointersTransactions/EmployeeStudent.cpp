#include "pch.h"
#include "Employee.h"
#include "EmployeeStudent.h"

void StudentEmployee::DevelopProduct()
{
	if (product)
	{
		(*(*product))->DoWork(step, name);

		float failureChance = RandomFloat(0.0f, 1.0f);
		if (failureChance < this->failureChance)
		{
			this->failureChance -= 0.05f;
			RevertProduct();
		}

		if ((*(*(product)))->IsReady())
		{
			std::cout << (*(*(product)))->GetName() << " developed" << std::endl;
			(*product)->Commit();
		}
	}
}

StudentEmployee::StudentEmployee(float step, float failureChance, std::string name)
{
	this->failureChance = failureChance;
	this->step = step;
	this->name = name;
}

StudentEmployee::~StudentEmployee()
{
}
