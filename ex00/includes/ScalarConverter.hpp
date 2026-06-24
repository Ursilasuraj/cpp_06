/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 07:14:57 by uvadakku          #+#    #+#             */
/*   Updated: 2026/06/20 15:39:37 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter &operator = (const ScalarConverter&);
	~ScalarConverter();
public:
  static void convert(std::string_view literal);
};
