#pragma once

class Student
{
public:
	enum SortField
	{
		nameSort,
		groupNumberSort,
		inGroupNumberSort,
		idSort
	};

	static SortField sortEnum;

	std::string name;
	std::string id;
	int groupNumber;
	int inGroupNumber;
	friend std::istream &operator>>(std::istream&, Student&);
	friend std::ostream &operator<<(std::ostream&, Student&);

	bool operator>(Student);
	bool operator<(Student);
	bool operator==(Student);

	std::string CalculateId();
	Student();
	~Student();

};