// FileStreams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BudgetException.h"
#include "Flower.h"
#include "FuneralTarget.h"
#include "AliveTarget.h"
#include "Target.h"
#include "Order.h"

int main()
{
	Flower flower;
	std::ifstream ifstream;
	ifstream.open("report.txt");
	while (!ifstream.eof())
	{
		std::cout << flower.GetCost() << flower.name.c_str();
	}
	ifstream.close();

	std::vector<Flower*> flowers;
	// мен€€ таргет можно тригерить четность заказа AliveTarget() или FuneralTarget()
	Target * target = new AliveTarget(100);
	//стоимость цветов и бюджет может тригерить исключение бюджета
	Flower * flower1 = new Flower(10,"flower1");
	Flower * flower2 = new Flower(20,"flower2");
	Flower * flower3 = new Flower(30,"flower3");
	Flower * flower4 = nullptr;

	try
	{
		flower4 = new Flower(-20.0f);//исключение в конструкторе
	}
	catch (float i)
	{
		std::cout << "constructor exception" << i << " " << (int)flower4 << std::endl;
		//оператор new не вернул указатель
	}

	Order * order = new Order(target);
	//измен€€ четность можно тригерить исключение четности заказа
	order->PutFlower(flower1);
	order->PutFlower(flower2);
	order->PutFlower(flower3);

	try
	{
		flowers = order->CommitOrder();
		std::ofstream stream;
		stream.open("report.txt", std::ofstream::out || std::ofstream::ate);

		for (auto i = flowers.begin(); i != flowers.end(); i++)
		{
			stream << (*i);
		}
		std::cout << "Order finished\n";
		stream.close();
	}
	catch (BudgetException* e)//исключение в бюджете, если суммарна€ сумма больше бюджета
	{
		std::cout << "budget limit exceded " << e->orderPrice << " of " << e->requiredBudget << std::endl;
		delete e;
	}
	catch (int e)
	{
		std::cout << "flowers quantity error " << e << std::endl;//вызываетс€ если нарушена четность количества цветов
	}
	catch (const std::exception& e)// прочие исключени€
	{
		std::cout << e.what() << std::endl;
	}

	delete flower1;
	delete flower2;
	delete flower3;
	delete target;
	delete order;
	system("pause");
	std::cout << "Hello World!\n";
}

