/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:01:43 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/16 15:19:09 by rrhnizar         ###   ########.fr       */
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


int	checkDot(std::string str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == '.')
			return 1;
		i++;
	}
	return 0;
}

int	checkF(std::string str)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == 'f')
			return 1;
		i++;
	}
	return 0;
}

/*function to implement */

void  convertToChar(std::string literal)
{
	size_t i = 0;
	int	checkPoint = 0;
	double res = strtod(literal.c_str(), NULL);

	if(literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (literal[i + 1] == 'f')
			{
				std::cout << "char : impossible" << std::endl;
				return ;
			}
			checkPoint++;
		}
		if ((i == literal.length() - 1 && isdigit((int)literal[i]) == 0 && literal[i] != 'f' && literal.length() > 1) \
				 || (literal[i] == 'f' && checkPoint == 0))
		{
			std::cout << "char : impossible" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.') || checkPoint > 1)
		{
			std::cout << "char: impossible" << std::endl;
			return ;
		}
		i++;
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
	if ((isdigit((int)literal[0]) && (res <= 31 || res > 126)) || literal[0] == '-')
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	if (literal.length() > 1 && isdigit(literal[0]) == 0 && literal[0] != '+' && literal[0] != '-')
		std::cout << "char: impossible" << std::endl;
	else
	{
		if(isdigit((int)literal[0]) == 0 && literal.length() >= 1 && literal[0] != '+' && literal[0] != '-')
			std::cout << "char: " << "'" << literal[0] << "'" << std::endl;
		else
			std::cout << "char: " << "'" << (char)res << "'" << std::endl;
	}
}

void  convertToInt(std::string literal)
{
	size_t i = 0;
	int	checkPoint = 0;
	double res = strtod(literal.c_str(), NULL);

	if(literal[i] == '+' || literal[i] == '-')
		i++;
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
	while (i < literal.length())
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
		i++;
	}
	std::cout << "int: ";
	std::cout << (int)res << std::endl;
}

void  convertToFloat(std::string literal)
{
	size_t i = 0;
	int	checkPoint = 0;
	double res = strtod(literal.c_str(), NULL);

	if(literal[i] == '+' || literal[i] == '-')
		i++;
	if (checkDot(literal))
	{
		if (checkF(literal))
			std::cout << std::fixed << std::setprecision(literal.length() - (literal.find('.')) - 2);
		else
			std::cout << std::fixed << std::setprecision(literal.length() - (literal.find('.')) - 1);
	}
	else
		std::cout << std::fixed << std::setprecision(1);
	if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" || literal == "nanf")
	{
		std::cout << "float: " << (float)res << "f" << std::endl;
		return ;
	}
	if (literal.length() == 1 && isdigit((int)literal[0]) == 0)
	{
		std::cout << "float: " << (int)literal[0] << ".0f" << std::endl;
		return ;
	}
	
	while (i <literal.length())
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
			std::cout << "float: impossible" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.' && literal[i] != '\0') || checkPoint > 1)
		{
			std::cout << "float: impossible" << std::endl;
			return;
		}
		i++;
	}
	std::cout << "float: ";
	std::cout << (double)res << "f" << std::endl;
}

void  convertToDouble(std::string literal)
{
	size_t i=0;
	int	checkPoint = 0;
	double res = strtod(literal.c_str(), NULL);

	if(literal[i] == '+' || literal[i] == '-')
		i++;
	if (checkDot(literal))
	{
		if (checkF(literal))
			std::cout << std::fixed << std::setprecision(literal.length() - (literal.find('.')) - 2);
		else
			std::cout << std::fixed << std::setprecision(literal.length() - (literal.find('.')) - 1);
	}
	else
		std::cout << std::fixed << std::setprecision(1);
	
	if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" || literal == "nanf")
	{
		std::cout << "double: " << (double)res << std::endl;
		return ;
	}
	if (literal.length() == 1 && isdigit((int)literal[0]) == 0)
	{
		std::cout << "double: " << (int)literal[0] << ".0" << std::endl;
		return ;
	}
	while (i <literal.length())
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
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		if ((isdigit((int)literal[i]) == 0 && i != literal.length() - 1 && literal[i] != '.' && literal[i] != '\0') || checkPoint > 1)
		{
			std::cout << "double: impossible" << std::endl;
			return;
		}
		i++;
	}
	std::cout << "double: ";
	std::cout << (double)res << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
