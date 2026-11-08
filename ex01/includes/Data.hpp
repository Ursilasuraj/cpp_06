/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: us <us@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:50:33 by us                #+#    #+#             */
/*   Updated: 2026/11/08 18:52:42 by us               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
    int _value;
public:
    Data();
    Data(const Data&other);
    Data &operator=(const Data&other);
    ~Data();
    Data(int value);
    int getValue() const;
};

#endif