#pragma once
class Order
{
	Target * target; //����������
	std::vector<Flower*> flowers;
public:
	void PutFlower(Flower*);
	float GetPrice() const;
	Order(Target*);
	const std::vector<Flower*>& CommitOrder() const;
	~Order();
};

