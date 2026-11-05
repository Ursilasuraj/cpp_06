/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:26:34 by us                #+#    #+#             */
/*   Updated: 2026/11/05 15:26:35 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <limits>
#include <stdexcept>
#include <string>

// Parse special floating-point literals such as nan and infinity.
static bool parsePseudoLiteral(std::string_view literal, double &value)
{
	if (literal == "nan" || literal == "nanf")
	{
		value = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	if (literal == "+inf" || literal == "inf"
		|| literal == "+inff" || literal == "inff")
	{
		value = std::numeric_limits<double>::infinity();
		return true;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		value = -std::numeric_limits<double>::infinity();
		return true;
	}
	return false;
}

// Parse a single non-digit character literal and convert it to double.
static bool parseCharacterLiteral(std::string_view literal, double &value)
{
	if (literal.size() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		value = static_cast<double>(literal[0]);
		return true;
	}
	return false;
}

// Parse decimal input, allowing the optional f suffix for float literals.
static bool parseNumericLiteral(std::string_view literal, double &value)
{
	try
	{
		const std::string input(literal);
		size_t idx = 0;
		value = std::stod(input, &idx);

		if (idx != input.size()
			&& !(idx + 1 == input.size() && input.back() == 'f'))
			return false;
		return true;
	}
	catch (const std::exception &)
	{
		return false;
	}
}

bool ScalarConverter::parseValue(std::string_view literal, double &value)
{
	if (parsePseudoLiteral(literal, value))
		return true;
	if (parseCharacterLiteral(literal, value))
		return true;
	return parseNumericLiteral(literal, value);
}
