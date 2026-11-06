/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:34:29 by us                #+#    #+#             */
/*   Updated: 2026/11/06 16:56:59 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.h"
#include "../includes/Data.h"

int main()
{
    Data data(42);

    std::cout << "Original Data value: "<< data.getValue() << std::endl;
    uintptr_t ptr = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(ptr); 
    std::cout << "Deserialized Data value: "<< deserializedData->getValue() << std::endl;
    return 0;
}