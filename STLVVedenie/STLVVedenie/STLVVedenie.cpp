// STLVVedenie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TourSeavice.h"

using namespace PrioriyQueueStructure;
using namespace QueueStructure;
using namespace StackStructure;

int main()
{
	PriorityQueue<TourSeavice*> * intersPriorityQueue = new PriorityQueue<TourSeavice*>;
	Stack<TourSeavice*> * intersStack = new Stack<TourSeavice*>;
	Queue<TourSeavice*>* intersQueue = new Queue<TourSeavice*>;

	Adapter<TourSeavice*>* inters = intersPriorityQueue;

	int exit = 0;
	int command;

	while (exit != 1)
	{
		std::cout << inters->name() << std::endl;
		_input("1)switch container 2) insert 3) top and edit 4)print all 5)exit", command, 1, 5);
		switch (command)
		{
		case 1:
		{
			int container = 0;
			_input("1) Stack 2) Queue 3) PriorityQueue", container);
			switch (container)
			{
			case 1:
			{
				inters = intersStack;
				break;
			}
			case 2:
			{
				inters = intersQueue;
				break;
			}
			case 3:
			{
				inters = intersPriorityQueue;
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2:
		{
			TourSeavice* tourService = new TourSeavice();
			std::cin >> *tourService;
			inters->Push(tourService);
			break;
		}
		case 3:
		{
			std::cout << *inters->Top();
			int edit = 1;
			_input("1)edit 2)skip", edit, 1, 2);
			if (edit == 1)
			{
				std::cin >> *inters->Top();
			}
			break;
		}
		case 4:
		{
			while (inters->Size() != 0)
			{
				std::cout << *inters->Pop();
			}
			break;
		}
		case 5:
		{
			exit = 1;
			break;
		}
		default:
			break;
		}
	}



	system("pause");
}
