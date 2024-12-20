#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iomanip>

template <typename T>
void showMatrix(const std::vector<std::vector<T>>& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto& elem : row)
		{
			std::cout << std::left << std::setw(8) << elem;
		}
		std::cout << "\n";
	}
}

#endif