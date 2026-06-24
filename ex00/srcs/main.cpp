/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 09:10:37 by uvadakku          #+#    #+#             */
/*   Updated: 2026/06/17 11:15:15 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
		if (argc != 2) 
		{
			std::cout << "Usage: " << argv[0] << " < literal >" << std::endl;
			return 1;
		}
		ScalarConverter::convert(argv[1]);
		return 0;
}

