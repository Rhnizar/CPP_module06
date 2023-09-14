/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:43 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/15 00:47:23 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& otherScalarConverter)
{
	*this = otherScalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& otherScalarConverter)
{
	if (this != &otherScalarConverter)
	{
		
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{}


/*function to implement */

void  convertToChar(std::string literal)
{
	size_t i;
	int	checkPoint = 0;
	double res = strtod(literal.c_str(), NULL);
	for(size_t i=0; i< literal.length(); i++)
	{
		if (literal[i] == '.')
			checkPoint++;
		// if (isdigit((int)literal[i]) == 0 && literal.length() > 1)
		// {
		// 	std::cout << "char: impossible" << std::endl;
		// 		return ;
		// }
	}
	if (checkPoint > 1)
	{
		std::cout << "char: impossible" << std::endl;
			return ;
	}
	if (res == 0 && isdigit((int)literal[0]))
	{
		if (literal.length() > 1)
		{
			for(i=0; i<literal.length(); i++)
			{
				if (literal[i] != '0')
					break;
			}
			if (i == literal.length())
			{
				std::cout << "char: Non displayable" << std::endl;
				return ;
			}
			else
			{
				std::cout << "char: impossible" << std::endl;
				return ;
			}
		}
	}
	if (isdigit((int)literal[0]) && res >= 0 && res <= 31)
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	if (literal.length() > 1 && isdigit(literal[0]) == 0)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if(isdigit((int)literal[0]) == 0)
			std::cout << "char: " << "'" << literal[0] << "'" << std::endl;
		else
			std::cout << "char: " << "'" << (char)res << "'" << std::endl;
	}
}

void  convertToInt(std::string literal)
{
	int	checkPoint = 0;
	size_t check_zero = 0;
	double res = strtod(literal.c_str(), NULL);
	if (res > INT_MAX || res < INT_MIN)
	{
		std::cout << "int: impossible"  << std::endl;
		return ;
	}
	if (literal.length() == 1 && isdigit((int)literal[0]) == 0)
	{
		std::cout << "int: " << (int)literal[0] << std::endl;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (literal[i + 1] == 'f')
			{
				std::cout << "int: impossible" << std::endl;
				return ;
			}
			checkPoint++;
		}
		if ((i == literal.length() - 1 && isdigit((int)literal[i]) == 0 && literal[i] != 'f') \
			 || (literal[i] == 'f' && checkPoint == 0))
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		
	}
	std::cout << "int: ";
	size_t i=0;
	if (i==0 && literal[i] == '0')
	{
		while(literal[i++] == '0')
			check_zero++;
		if (check_zero != 0 && literal.length() == check_zero && res != 0)
			std::cout << '0' ;
	}
	std::cout << (int)res << std::endl;
}

void  convertToFloat(std::string literal)
{
	std::cout << std::fixed << std::setprecision((literal.find('.')) - 1);
	int	checkPoint = 0;
	size_t check_zero = 0;
	double res = strtod(literal.c_str(), NULL);
	if (literal == "inf" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "float: " << (double)res << "f" << std::endl;
		return ;
	}

	if (literal.length() == 1 && isdigit((int)literal[0]) == 0)
	{
		std::cout << "float: " << (int)literal[0] << ".0f" << std::endl;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (literal[i + 1] == 'f')
			{
				std::cout << "float: impossible" << std::endl;
				return ;
			}
			checkPoint++;
		}
		
		if(isdigit((int)literal[i]) == 0 && literal[i] != '.' && literal.length() > 1 && literal[literal.length() - 1] != 'f')
		{
			std::cout << "float: nanf" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "float: impossible" << std::endl;
			return;
		}
	}
	std::cout << "float: ";
	size_t i=0;
	if (i==0 && literal[i] == '0')
	{
		while(literal[i++] == '0')
			check_zero++;
		if (check_zero != 0 && literal.length() == check_zero && res != 0)
			std::cout << '0';
	}
	std::cout << (float)res << "f" << std::endl;
}

void  convertToDouble(std::string literal)
{
	std::cout << std::fixed << std::setprecision((literal.find('.')) - 1);
	
	int	checkPoint = 0;
	size_t check_zero = 0;
	double res = strtod(literal.c_str(), NULL);
	
	if (literal == "inf" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "double: " << (double)res  << std::endl;
		return ;
	}
	if (literal.length() == 1 && isdigit((int)literal[0]) == 0)
	{
		std::cout << "double: " << (int)literal[0] << ".0" << std::endl;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (literal[i + 1] == 'f')
			{
				std::cout << "double: impossible" << std::endl;
				return ;
			}
			checkPoint++;
		}
		if(isdigit((int)literal[i]) == 0 && literal[i] != '.' && literal.length() > 1 && literal[literal.length() - 1] != 'f')
		{
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	std::cout << "double: ";
	size_t i=0;
	if (i==0 && literal[i] == '0')
	{
		while(literal[i++] == '0')
			check_zero++;
		if (check_zero != 0 && literal.length() == check_zero && res != 0)
			std::cout << '0' ;
	}
	std::cout << (double)res << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
