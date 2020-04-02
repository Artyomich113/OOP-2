#include "pch.h"
#include "Employee.h"

void Employee::SetProduct(Product *prod)
{
	product = new SmartPointer<Transaction<Product>>(new Transaction<Product>(prod));
}

void Employee::StartDevelop()
{
	(*product)->BeginTrans();
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
