/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:45:06 by uvadakku          #+#    #+#             */
/*   Updated: 2026/06/24 08:12:27 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string_view literal) {
  (void)literal;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string_view_literal)
{
	double d;
	
	if (literal == "nan" || literal == "nanf") 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
}

if (literal.length() == 1 && !std::isdigit(literal[0]))
{
	d = static_cast<double>([literal[0]])
}
else 
	try {
		size_t idx;
		d = std::stod(std::string(literal))
		if ()
	}
}