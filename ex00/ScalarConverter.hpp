/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:23:33 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/15 00:46:27 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdlib> // Include the C Standard Library header

class ScalarConverter
{
  public:
    ScalarConverter();//default constractor
    ScalarConverter(const ScalarConverter& otherScalarConverter);//copy constractor
    ScalarConverter& operator=(const ScalarConverter& otherScalarConverter);//copy assignement operator
    ~ScalarConverter();//destractor
    void convert(std::string literal);
};


void  convertToChar(std::string literal);
void  convertToInt(std::string literal);
void  convertToFloat(std::string literal);
void  convertToDouble(std::string literal);

#endif