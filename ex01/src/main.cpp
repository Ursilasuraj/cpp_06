/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:34:29 by us                #+#    #+#             */
/*   Updated: 2026/11/08 18:49:32 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main()
{
    Data data(42);

    std::cout << "Original Data value: "<< data.getValue() << std::endl;
    uintptr_t ptr = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(ptr); 
    std::cout << "Deserialized Data value: "<< deserializedData->getValue() << std::endl;
    return 0;
}