#pragma once
#include "pch.h"

void _inputString(const std::string & massage, std::string & in, bool includeSpaces);

template <typename T> void _input(const std::string & massage, T & in) {
	std::cout << massage << std::endl;
	std::cin >> in;
	while (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "error : " << massage;
		std::cin >> in;
	}
}

template <typename T> void _input(const std::string & massage, T & in, T left, T right) {
	std::cout << massage << std::endl;
	std::cin >> in;
	while (!std::cin.good() || (in <left || in > right)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "error ( " << left << ":" << right << ") " << massage;
		std::cin >> in;
	}
}









