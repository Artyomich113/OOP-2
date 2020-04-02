#pragma once
class Product
{
	std::string name;
	float process;
public:
	void DoWork(float, std::string);
	bool IsReady()
	{
		return process >= 1.0f;
	}
	std::string GetName();
	Product* operator=(Product);
	Product();
	Product(std::string);
	~Product();
};

