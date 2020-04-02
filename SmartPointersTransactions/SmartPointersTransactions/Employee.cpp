#include "pch.h"
#include "Employee.h"

void Employee::SetProduct(SmartPointer<Transaction<Product>> *prod)
{
	product = new SmartPointer<Transaction<Product>>(*prod);
}

void Employee::StartDevelop()
{
	if (product)
	{
		if (!(*product)->IsActive())
			(*product)->BeginTrans();
	}
}

void Employee::RevertProduct()
{
	std::cout << "Revert " << (*(*product))->GetName() << std::endl;
	if (product)
		(*product)->Revert();
}

void Employee::ReleaseProduct()
{
	delete product;
}

Employee::Employee()
{
}


Employee::~Employee()
{
}
