#pragma once
class StudentEmployee : public Employee
{
	float failureChance = 0.9f;
public:
	void DevelopProduct();
	StudentEmployee(float step,float failureChance, std::string name);
	~StudentEmployee();
};

