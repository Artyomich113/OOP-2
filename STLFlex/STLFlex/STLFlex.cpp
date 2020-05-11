// STLFlex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Student.h"
#include "Input.h"

bool compare_less(Student* student1, Student* student2)
{
	return (*student1) < (*student2);
}

int main()
{

	Student::sortEnum = Student::SortField::idSort;

	std::list<Student*> students;

	std::map<std::string, Student*> studentsById;
	int exit = 0;
	while (exit != 1)
	{
		int command;
		_input("1)add student 2)find and edit 3) remove student 4) view students 5) sort 6) load in file 7)exit", command, 1, 7);
		switch (command)
		{
		case 1:
		{

			Student *student = new Student;

			std::cin >> *student;

			students.push_back(student);
			studentsById.insert(std::pair<std::string, Student*>(student->id, student));
			break;
		}
		case 2:
		{
			for (auto it = studentsById.begin(); it != studentsById.end(); it++)
			{
				std::cout << (*it).first << std::endl;
			}

			std::string id = "";
			std::cout << "id:" << std::endl;
			std::cin >> id;

			
			auto st = studentsById.find(id);
			if (st != studentsById.end())
			{
				std::cout << (*st).first;
				std::cin >> *(*st).second;
			}
			else
			{
				std::cout << "not found " << std::endl;
			}
			break;
		}
		case 3:
		{
			for (auto it = studentsById.begin(); it != studentsById.end(); it++)
			{
				std::cout << (*it).first;
			}


			std::string id = "";
			std::cout << "id:" << std::endl;
			std::cin >> id;

			auto st = studentsById.find(id);
			if (st != studentsById.end())
			{
				students.remove((*st).second);
				studentsById.erase(st);
			}
			break;

		}
		case 4:
			for (auto iterator = students.begin(); iterator != students.end(); iterator++)
			{
				std::cout << *(*iterator);
			}
			break;
		case 5:
		{

			int sort = 0;
			_input("1)name 2)groupNumber 3)inGroupNumber 4) idSort", sort);
			switch (sort)
			{
			case 1: Student::sortEnum = Student::nameSort;
				break;
			case 2:Student::sortEnum = Student::groupNumberSort;
				break;
			case 3:Student::sortEnum = Student::inGroupNumberSort;
				break;
			case 4:Student::sortEnum = Student::idSort;
				break;
			default:
				break;
			}
			students.sort(compare_less);
			break;
		}
		case 6:
		{
			std::ofstream stream;
			stream.open("report.txt", std::ofstream::trunc);

			for (auto student : students)
			{
				stream << student->name << std::endl;
				stream << student->groupNumber << std::endl;
				stream << student->inGroupNumber << std::endl;
				stream << student->id << std::endl;
			}
			stream.close();
			break;
		}
		case 7:
			exit = 1;
			break;
		default:
			break;
		}
	}
	std::cout << "Hello World!\n";
}
