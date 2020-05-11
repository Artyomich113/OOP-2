#include "pch.h"
#include "TourSeavice.h"


TourSeavice::TourSeavice()
{
	name = "";
	cost = 0;
}

std::istream & operator>>(std::istream & stream, TourSeavice & tour)
{
	stream >> tour.name >> tour.cost;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, TourSeavice & tour)
{
	stream << tour.name << std::endl << tour.cost << std::endl;
	return stream;
}

TourSeavice::~TourSeavice()
{
}

TourSeavice::TourSeavice(std::string name, int cost)
{
	this->name = name;
	this->cost = cost;
}

bool TourSeavice::operator<(TourSeavice &tourService)
{
	return this->cost < tourService.cost;
}

bool TourSeavice::operator>(TourSeavice &tourService)
{
	return this->cost > tourService.cost;
}
