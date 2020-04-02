#include "pch.h"
#include "Publisher.h"

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
