// SmartPointersTransactions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include "Publisher.h"
#include "ChadEmployee.h"
#include "EmployeeStudent.h"
#include <exception>

int main()
{
	Product * product1 = new Product("prod1");
	Product * product2 = new Product("prod2");
	
	Publisher * publisher = new Publisher();
	
	Employee * employee1 = new ChadEmployee(0.18f, "chad1");
	Employee * employee2 = new StudentEmployee(0.21f,0.39f, "student1");
	
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

