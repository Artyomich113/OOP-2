#pragma once
class Order
{
	Target * target; //композиция
public:
	std::vector<Flower*> flowers;
	void PutFlower(Flower*);
	void PutTarget(Target *);
	void Remove(std::vector<Flower*>::iterator it);
	float GetPrice() const;
	Order(Target*);
	Order();
	const std::vector<Flower*>& CommitOrder() const;
	~Order();
};

