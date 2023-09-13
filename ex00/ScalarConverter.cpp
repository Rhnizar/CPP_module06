/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:43 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/13 13:51:18 by rrhnizar         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

void  convertToChar(std::string literal)
{
	int res = ft_atoi(literal.c_str());
	if (isdigit(res + 48) && res >= 0 && res <= 31)
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	if (literal.length() > 1 && isdigit(literal[0]) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << (char)res << "'" << std::endl;
}

void  convertToInt(std::string literal)
{
	int	checkPoint = 0;
	if (literal.length() == 1 && isdigit(literal[0]) == 0)
	{
		std::cout << "int: " << literal[0] << std::endl;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
			checkPoint++;
		if (i == literal.length() - 1 && isdigit(literal[i]) == 0 && literal[i] != 'f')
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		if ((isdigit(literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
	}
	std::cout << "int: ";
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
		{
			std::cout << literal[i];
			while(literal[i++] == '0');
		}
		if (literal[i] == '.')
			break;
		std::cout << literal[i];
	}
	std::cout << std::endl;
}

void  convertToFloat(std::string literal)
{
	int	checkPoint = 0;
	if (literal.length() == 1 && isdigit(literal[0]) == 0)
	{
		std::cout << "float: " << literal[0] << ".0f" << std::endl;;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
			checkPoint++;
		if (i == literal.length() - 1 && isdigit(literal[i]) == 0 && literal[i] != 'f')
		{
			std::cout << "float: nanf" << std::endl;
			return ;
		}
		if ((isdigit(literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "float: nanf" << std::endl;
			return;
		}
	}
	std::cout << "float: ";
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
		{
			std::cout << literal[i];
			while(literal[i++] == '0');
		}
		if (literal[i] == '.')
			break;
		std::cout << literal[i];
	}
	std::cout << ".0f" << std::endl;
}

void  convertToDouble(std::string literal)
{
	int	checkPoint = 0;
	if (literal.length() == 1 && isdigit(literal[0]) == 0)
	{
		std::cout << "double: " << literal[0] << ".0" << std::endl;
		return ;
	}
	for (size_t i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
			checkPoint++;
		if (i == literal.length() - 1 && isdigit(literal[i]) == 0 && literal[i] != 'f')
		{
			std::cout << "double: nan" << std::endl;
			return ;
		}
		if ((isdigit(literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "double: nan" << std::endl;
			return;
		}
	}
	std::cout << "double: ";
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
		{
			std::cout << literal[i];
			while(literal[i++] == '0');
		}
		if (literal[i] == 'f' || literal[i] == '.')
			break;
		std::cout << literal[i];
	}
	std::cout << ".0" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}