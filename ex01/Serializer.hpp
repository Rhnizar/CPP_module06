/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:11:02 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/16 12:54:07 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
	int value;
};

class Serializer
{
	public:
		Serializer();//constractor
		Serializer(const Serializer& otherSerializer);// copy constractor
		Serializer& operator=(const Serializer& otherSerializer);// copy assignement operator overloading
		~Serializer();//destractor
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif