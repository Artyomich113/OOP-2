#include "pch.h"
#include "Input.h"

void _inputString(const std::string & massage, std::string & in, bool includeSpaces)
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << massage << std::endl;
	
	if (includeSpaces)
		std::getline(std::cin, in);
	else
		std::cin >> in;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "error : " << massage;
		if (includeSpaces)
			std::getline(std::cin, in);
		else
			std::cin >> in;
	}
}
