#pragma once
#include "Product.h"

class Employee
{
	std::string name;
	float step;
	SmartPointer<Transaction<Product>> * product;
public:
	Employee(std::string,float);
	const float failureChance = 0.9f;
	void SetProduct(Product *);
	void StartDevelop();
	void DevelopProduct();
	void RevertProduct();
	Employee();
	~Employee();
};

