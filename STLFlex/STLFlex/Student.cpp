#include "pch.h"
#include "Student.h"
#include "Input.h"

Student::SortField Student::sortEnum;

bool Student::operator>(Student student)
{

	bool flag = false;
	switch (Student::sortEnum)
	{
	case groupNumberSort:
		flag = this->groupNumber > student.groupNumber;
		break;
	case idSort:
		flag = this->id > student.id;
		break;
	case inGroupNumberSort:
		flag = this->inGroupNumber > student.inGroupNumber;
		break;
	case nameSort:
		flag = this->name > student.name;
		break;
	default:
		flag = false;
		break;
	}
	return flag;
}

bool Student::operator<(Student student)
{
	bool flag = false;
	switch (Student::sortEnum)
	{
	case groupNumberSort:
		flag = this->groupNumber < student.groupNumber;
		break;
	case idSort:
		flag = this->id < student.id;
		break;
	case inGroupNumberSort:
		flag = this->inGroupNumber < student.inGroupNumber;
		break;
	case nameSort:
		flag = this->name < student.name;
		break;
	default:
		flag = false;
		break;
	}
	return flag;
}

bool Student::operator==(Student student)
{
	bool flag = false;
	switch (Student::sortEnum)
	{
	case Student::SortField::groupNumberSort:
		flag = this->groupNumber == student.groupNumber;
		break;
	case Student::SortField::idSort:
		flag = this->id == student.id;
		break;
	case Student::SortField::inGroupNumberSort:
		flag = this->inGroupNumber == student.inGroupNumber;
		break;
	case Student::SortField::nameSort:
		flag = this->name == student.name;
		break;
	default:
		flag = false;
		break;
	}
	return flag;
}

std::string Student::CalculateId()
{
	id = std::to_string(groupNumber) + std::to_string(inGroupNumber);

	return id;
}

Student::Student()
{
}

Student::~Student()
{
}

std::istream & operator>>(std::istream & stream, Student & student)
{
	_input("name", student.name);
	_input("group number", student.groupNumber);
	_input("in group number", student.inGroupNumber);
	student.CalculateId();
	return stream;
}

std::ostream & operator<<(std::ostream &stream, Student &student)
{
	stream << student.name << " " << student.groupNumber << " " << student.inGroupNumber << " " << student.id << std::endl;
	return stream;
}
