// SmartPointersTransactions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include "Publisher.h"
#include <exception>

int main()
{
	Product * product1 = new Product("prod1");
	Product * product2 = new Product("prod2");
	
	Publisher * publisher = new Publisher();
	
	Employee * employee1 = new Employee("epm1",0.08);
	Employee * employee2 = new Employee("emp2",0.13);
	
	publisher->AddEmployee(employee1);
	publisher->AddEmployee(employee2);
	
	publisher->AddProduct(product1);
	publisher->AddProduct(product2);

	publisher->DevelopProducts();


	delete product1;
	delete product2;
	
	delete employee1;
	delete employee2;

	delete publisher;
	system("pause");
}

