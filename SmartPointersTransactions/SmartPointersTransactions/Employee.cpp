#include "pch.h"
#include "Employee.h"

Employee::Employee(std::string name_, float step_):name(name_),step(step_)
{
}

void Employee::SetProduct(Product *prod)
{
	product = new SmartPointer<Transaction<Product>>(new Transaction<Product>(prod));
}

void Employee::StartDevelop()
{
	(*product)->BeginTrans();
}

void Employee::DevelopProduct()
{
	if (product)
	{

		(*(*product))->DoWork(step);
		if ((*(*(product)))->IsReady())
		{
		std::cout << (*(*(product)))->GetName() << " developed" << std::endl;
			(*product)->Commit();
		}
	}
}

void Employee::RevertProduct()
{
	std::cout << "Revert " << (*(*product))->GetName() << std::endl;
	if (product)
		(*product)->Revert();
}

Employee::Employee()
{
}


Employee::~Employee()
{
}
