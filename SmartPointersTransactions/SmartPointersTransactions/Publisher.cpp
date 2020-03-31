#include "pch.h"
#include "Publisher.h"

float RandomFloat(float min, float max)
{
	assert(max > min);
	float random = ((float)rand()) / (float)RAND_MAX;

	float range = max - min;
	return (random*range) + min;
}

void Publisher::DevelopProducts()
{
	for (Product* emp: products)
	{
		int index = rand() % Employees.size();
		Employee *employee = Employees[index];
		
		employee->SetProduct(emp);
		
		employee->StartDevelop();

		while (!emp->IsReady())
		{
			employee->DevelopProduct();

			float failureChance = RandomFloat(0.0f, 1.0f);
			if (failureChance > employee->failureChance)
			{
				employee->RevertProduct();
			}
		}
		Employees.erase(Employees.begin() + index);
	}
}

void Publisher::AddEmployee(Employee* emp)
{
	Employees.push_back(emp);
}

void Publisher::AddProduct(Product *prd)
{
	products.push_back(prd);
}

Publisher::Publisher()
{

}


Publisher::~Publisher()
{
}
