/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:31:32 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/13 17:12:49 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <sstream>
#include <iomanip>


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	 index = 0;
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


		std::cout << "char : " << (char)index << std::endl;
		std::cout << "int : " << index << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(1) << indexfloat << 'f' << std::endl;
		std::cout << "double : " <<  std::fixed << std::setprecision(1) << indexdouble<< std::endl;

	}
	return 0;
}
