
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
		_input("1)insert 2) search 3) report 4) construct 5) create target 6) fill order  8) commit 9)exit 10) view", command, 1, 10);
		switch (command)
		{
		case 1:
		{
			Flower * flower = new Flower();
			_inputString("name", flower->name, true);
			_input("cost", flower->cost);
			flowers.push_back(flower);
			break;
		}
		case 2:
		{
			if (flowers.empty())
				break;

			int search = 0;
			std::vector<Flower*>::iterator iterator = flowers.end();
			_input("1)name 2)cost 3)cancel", search, 1, 3);
			switch (search)
			{
			case 1:
			{
				std::string name;
				_input("name ", name);
				for (auto it = flowers.begin(); it != flowers.end(); it++)
				{
					if ((*it)->name == name)
					{
						iterator = it;
					}
				}
				break;
			}
			case 2:
			{
				int cost;
				_input("cost ", cost);
				for (auto it = flowers.begin(); it != flowers.end(); it++)
				{
					if ((*it)->cost == cost)
					{
						iterator = it;
					}
				}
				break;
			}
			default:
				break;
			}

			if (iterator != flowers.end())
			{
				int operation = 0;
				_input("1)remove 2) edit 3) cancel", operation, 1, 3);
				switch (operation)
				{
				case 1:
				{
					flowers.erase(iterator);
					break;
				}
				case 2:
				{
					std::cout << "Enter name and cost \n";
					std::cin >> *(*iterator);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 3:
		{
			std::ofstream stream;
			stream.open("report.txt", std::ofstream::trunc);
			for (auto flower : flowers)
			{
				stream << *flower;
			}
			stream.close();
			break;
		}
		case 4:
		{
			std::ifstream stream;
			stream.open("report.txt");
			while (!stream.eof())
			{
				Flower* flower = new Flower;
				stream >> *flower;
				if (!stream.eof())
					flowers.push_back(flower);
				else
				{
					delete flower;
				}
			}

			stream.close();
			break;
		}
		case 5:
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
		case 6:
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
		
		case 8:
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
		case 9:
			exit = 1;
			break;
		case 10:
		{
			for (auto flower : flowers)
			{
				std::cout << *flower;
			}
			break;
		}
		default:
			break;
		}
	}

	std::ofstream stream;
	
	for (auto it = flowers.begin(); it != flowers.end(); it++)
	{
		delete *it;
	}

	system("pause");
	std::cout << "Hello World!\n";
}

