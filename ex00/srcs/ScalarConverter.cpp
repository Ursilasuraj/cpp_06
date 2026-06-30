/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:45:06 by uvadakku          #+#    #+#             */
/*   Updated: 2026/06/29 16:06:59 by uvadakku         ###   ########.fr       */
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


static bool isPseudoLiteral(std::string_view literal)
{
	return literal == "nan" || literal == "nanf"
	|| literal == "+inf" || literal == "-inf"
	|| literal == "inf" || literal == "+inff"
	|| literal == "+inff" || literal == "-inff";
}

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
			std::cout << "Non displayble";
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
		std::cout << "impossible:";
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

static bool parseValue(std::string_view literal, double &value)
{
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		value = static_cast<double>(literal[0]);
		return true;
	}
	try
	{
		const std::string input(literal);
		size_t idx = 0;
		value = std::stod(input, &idx);

		if (idx != input.size())
		{
			if (!(idx + 1 == input.size() && input.back() == 'f'))
				return false;
		}
		return true;
	}
	catch (const std::exception &)
	{
		return false;
	}
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

	if (isPseudoLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
		printAllTypes(value);
		return;
	}
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

