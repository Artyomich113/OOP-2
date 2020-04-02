#include "pch.h"
#include "Publisher.h"

void Publisher::DevelopProducts()
{
	for (Product* emp : products)
	{
		Transaction<Product> * productTransaction = new Transaction<Product>(emp);

		SmartPointer<Transaction<Product>> * productTransactionSmartPointer = new SmartPointer<Transaction<Product>>(productTransaction);
		for (auto it = Employees.begin(); it != Employees.end(); it++)
		{
			(*it)->SetProduct(productTransactionSmartPointer);
		}

		while (!emp->IsReady())
		{
			int index = rand() % Employees.size();
			Employee *employee = Employees[index];

			employee->StartDevelop();

			employee->DevelopProduct();
		}

		for (auto it = Employees.begin(); it != Employees.end(); it++)
		{
			(*it)->ReleaseProduct();
		}
		delete productTransactionSmartPointer;
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
