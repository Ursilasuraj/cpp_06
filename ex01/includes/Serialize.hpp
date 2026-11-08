/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:52:59 by us                #+#    #+#             */
/*   Updated: 2026/11/08 18:55:05 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer &operator=(const Serializer&);
    ~Serializer();
public:
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif