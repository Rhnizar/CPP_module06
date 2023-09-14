/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:31:32 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/13 17:44:22 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <sstream>
#include <iomanip>


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



int main(int argc, char **argv)
{
	if (argc == 2)
	{
		// int res = ft_atoi(argv[1]);
		int	 	index = 0;
		float	 indexfloat = 0.0f;
		double	indexdouble = 0.0;
	
		std::stringstream sInt;
		std::stringstream sFloat;
		std::stringstream sDouble;
		
		sInt << argv[1];
		sInt >> index;

		sFloat << argv[1];
		sFloat >> indexfloat;
		
		sDouble << argv[1];
		sDouble >> indexdouble;


		std::cout << "char : " << index << std::endl;
		std::cout << "int : " << (int)index << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(1) << indexfloat << 'f' << std::endl;
		std::cout << "double : " <<  std::fixed << std::setprecision(1) << indexdouble<< std::endl;

	}
	return 0;
}
