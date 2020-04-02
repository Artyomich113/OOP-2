#pragma once
#include "Product.h"

class Employee
{
protected:
	std::string name;
	float step;
	SmartPointer<Transaction<Product>> * product;
public:
	void SetProduct(SmartPointer<Transaction<Product>> *);
	void StartDevelop();
	virtual void DevelopProduct() = 0;
	void RevertProduct();
	void ReleaseProduct();
	Employee();
	~Employee();
};

