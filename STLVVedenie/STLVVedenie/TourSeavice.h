#pragma once
class TourSeavice
{
public:
	std::string name;
	int cost;
	TourSeavice();
	~TourSeavice();
	friend std::istream & operator >>(std::istream& s, TourSeavice & d);
	friend std::ostream & operator <<(std::ostream& s, TourSeavice & d);
	TourSeavice(std::string name, int cost);
	bool operator<(TourSeavice& tourService);
	bool operator>(TourSeavice& tourService);
};

