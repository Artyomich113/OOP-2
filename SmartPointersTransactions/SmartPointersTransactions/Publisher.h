#pragma once
#include "Employee.h"

class Publisher
{
	std::vector<Employee*> Employees;
	std::list<Product*> products;
public:
	void DevelopProducts();
	void AddEmployee(Employee *);
	void AddProduct(Product *);
	Publisher();
	~Publisher();
};

