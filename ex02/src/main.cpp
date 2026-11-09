/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:43:36 by uvadakku          #+#    #+#             */
/*   Updated: 2026/11/09 15:24:55 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Test " << i + 1 << std::endl;
        Base *basePtr = generate();
        std::cout << "Generated: " << basePtr << std::endl;
        identify(basePtr);
        identify(*basePtr);
        delete basePtr;
    }
    return 0;
}
