#pragma once
class Flower
{
public:
	float cost;
	std::string name;
	Flower(float, std::string);
	Flower(float);
	Flower();
	~Flower();
	float GetCost();
	friend std::istream & operator >>(std::istream& s, Flower & d);
	friend std::ostream & operator <<(std::ostream& s, Flower & d);


};

