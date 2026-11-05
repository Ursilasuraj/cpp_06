/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:45:06 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/05 15:22:49 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cctype>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}


static bool isIntegerValue(double value)
{
	return std::isfinite(value) && value == static_cast<long long>(value);
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (!std::isfinite(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible";
	}
	else
	{
		char c = static_cast<char>(value);
		if (std::isprint(static_cast<unsigned char>(c)))
		{
			std::cout << "'" << c << "'";
		}
		else
		{
			std::cout << "Non displayable";
		}
		std::cout << '\n';
	}
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (!std::isfinite(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << static_cast<int>(value);
	}
	std::cout << '\n';
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf";
	else if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inff";
		else
			std::cout << "+inff";
	}
	else if (isIntegerValue(value))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value);
	else
		std::cout << std::defaultfloat << static_cast<float>(value);
	std::cout << 'f' << '\n';
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "-inf";
		else
			std::cout << "+inf";
	}
	else if (isIntegerValue(value))
		std::cout << std::fixed << std::setprecision(1) << value;
	else
		std::cout << std::defaultfloat << value;
	std::cout << '\n';
}

static void printAllTypes(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(std::string_view literal)
{
	double value;

	if (!parseValue(literal, value))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	printAllTypes(value);
}

