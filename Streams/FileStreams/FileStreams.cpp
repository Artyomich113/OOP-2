
#include "pch.h"
#include "Input.h"
#include "BudgetException.h"
#include "Flower.h"
#include "FuneralTarget.h"
#include "AliveTarget.h"
#include "Target.h"
#include "Order.h"

int main()
{
	int exit = 0;
	std::vector<Flower*> flowers;
	Target * target = new AliveTarget(100);
	Order * order = new Order();

	while (exit != 1)
	{
		int command = 0;
		_input("1) insert flowers  2) edit flower 3)find 4) create target 5) fill order 6) remove 7) commit 8)exit ", command, 1, 8);
		switch (command)
		{
		case 1:
		{
			Flower * flower = new Flower();
			std::cin >> *flower;
			flowers.push_back(flower);
			break;
		}
		case 2:
		{
			int id = 0;
			for (auto it = flowers.begin(); it != flowers.end(); it++)
			{
				std::cout << it - flowers.begin() << " " << *(*it) << std::endl;
			}
			_input("id ", id, 0, flowers.end() - flowers.begin() - 1);
			std::cin >> *flowers[id];
			break;
		}
		case 3:
		{
			int find = 0;
			auto it = flowers.end();
			_input("1)cost 2)name", find, 1, 2);
			switch (find)
			{
			case 1:
			{
				int cost = 0;
				_input("cost", cost);
				for (auto i : flowers)
				{
					if (i->GetCost() == cost)
					{
						std::cout << *i;
					}
				}
				break;
			}
			case 2:
			{
				std::string name;
				_inputString("name", name,true);
				for (auto i : flowers)
				{
					if (i->name == name)
					{
						std::cout << *i << std::endl;
					}
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4:
		{

			int targetType = 0;
			int budget;
			_input("1) Alive 2) Funeral", targetType, 1, 2);
			_input("budget", budget, 0, 10000);
			if (target)
			{
				delete target;
			}
			switch (targetType)
			{
			case 1:
				target = new AliveTarget(budget);
				break;
			case 2:
				target = new FuneralTarget(budget);
				break;
			default:
				break;
			}
			order->PutTarget(target);
			break;
		}
		case 5:
		{
			int id = 0;
			for (auto it = flowers.begin(); it != flowers.end(); it++)
			{
				std::cout << it - flowers.begin() << " " << *(*it) << std::endl;
			}
			_input("id ", id, 0, flowers.end() - flowers.begin() - 1);

			order->PutFlower(flowers[id]);
			break;
		}
		case 6:
		{
			int id = 0;
			for (auto it = order->flowers.begin(); it != order->flowers.end(); it++)
			{
				std::cout << it - order->flowers.begin() << " " << *(*it) << std::endl;
			}

			_input("id", id, 0, order->flowers.end() - order->flowers.begin() - 1);

			auto iterator = order->flowers.begin() + id;
			std::cout << *(*iterator) << " removed";

			order->Remove(iterator);
			break;
		}
		case 7:
		{

			try
			{
				std::vector<Flower*> localFlowers = order->CommitOrder();
				std::cout << "Order finished\n";
				for (auto it = localFlowers.begin(); it != localFlowers.end(); it++)
				{
					std::cout << *(*it) << std::endl;
				}
			}
			catch (BudgetException* e)//исключение в бюджете, если суммарная сумма цветов больше бюджета
			{
				std::cout << "budget limit exceded " << e->orderPrice << " of " << e->requiredBudget << std::endl;
				delete e;
			}
			catch (int e)
			{
				std::cout << "flowers quantity error " << e << std::endl;//вызывается если нарушена четность количества цветов
			}
			catch (const std::exception& e)// прочие исключения
			{
				std::cout << e.what() << std::endl;
			}
			break;
		}
		case 8:
			exit = 1;
		default:
			break;
		}
	}

	for (auto it = flowers.begin(); it != flowers.end(); it++)
	{
		delete *it;
	}

	system("pause");
	std::cout << "Hello World!\n";
}

