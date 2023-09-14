/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:43 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/14 13:56:34 by rrhnizar         ###   ########.fr       */
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
	size_t i;
	int	checkPoint = 0;
	int res = ft_atoi(literal.c_str());
	for(size_t i=0; i< literal.length(); i++)
	{
		if (literal[i] == '.')
			checkPoint++;
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
	double res = std::strtod(literal.c_str(), NULL);

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
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
			while(literal[i++] == '0')
				check_zero++;
			if (check_zero != 0 && literal.length() == check_zero)
				std::cout << '0' ;
	
		if (literal[i] == '.')
			break;
		std::cout << literal[i];
	}
	std::cout << std::endl;
}

void  convertToFloat(std::string literal)
{
	// std::cout << std::fixed << std::setprecision((literal.length() - literal.find('.') - 2));
	
	int	checkPoint = 0;
	size_t check_zero = 0;
	double res = std::strtod(literal.c_str(), NULL);

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
		if ((i == literal.length() - 1 && isdigit((int)literal[i]) == 0 && literal[i] != 'f') \
		|| (literal[i] == 'f' && checkPoint == 0))
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
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
			while(literal[i++] == '0')
				check_zero++;
			if (check_zero != 0 && literal.length() == check_zero)
				std::cout << '0' ;
	}
	size_t i;
	for(i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
			break;
	}
	if (i == literal.length())
	{
		std::cout << (float)res << ".0f" << std::endl;
		return;
	}
	else
	{
		while(i++ < literal.length())
		{
			if(literal[i] != '0')
				break;
		}
		if (i == literal.length() || literal[i] == 'f')
			std::cout << (float)res << ".0f" << std::endl;
		else
			std::cout << (float)res << "f" << std::endl;
	}
}

void  convertToDouble(std::string literal)
{
	// std::cout << std::fixed << std::setprecision((literal.length() - literal.find('.') - 2));
	
	int	checkPoint = 0;
	size_t check_zero = 0;
	double res = std::strtod(literal.c_str(), NULL);

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
		if ((i == literal.length() - 1 && isdigit((int)literal[i]) == 0 && literal[i] != 'f') \
		|| (literal[i] == 'f' && checkPoint == 0))
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
	for (size_t i=0; i<literal.length(); i++)
	{
		if (i==0 && literal[i] == '0')
			while(literal[i++] == '0')
				check_zero++;
			if (check_zero != 0 && literal.length() == check_zero)
				std::cout << '0' ;
		if (literal[i] == 'f')
			break;
	}
	size_t i;
	for(i=0; i<literal.length(); i++)
	{
		if (literal[i] == '.')
			break;
	}
	if (i == literal.length())
	{
		std::cout << (double)res << ".0" << std::endl;
		return;
	}
	else
	{
		while(i++ < literal.length())
		{
			if(literal[i] != '0')
				break;
		}
		if (i == literal.length() || literal[i] == 'f')
			std::cout << (double)res << ".0" << std::endl;
		else
			std::cout << (double)res << std::endl;
	}
}

void ScalarConverter::convert(std::string literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
