/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:10:37 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/05 15:00:55 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
		if (argc != 2) 
		{
			std::cout << "Enter a char/int/float/double literal: " << std::endl;
			return 1;
		}
		ScalarConverter::convert(argv[1]);
		return 0;
}

