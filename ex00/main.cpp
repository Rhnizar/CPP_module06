/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:23:00 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/13 12:21:01 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter Sc;
        Sc.convert(argv[1]);
        // std::cout << "char : " << argv[0][0] << std::endl;
        // std::cout << "int : " << (int)argv[0][0] << std::endl;
        // std::cout << "float : " << (float)argv[0][0] << std::endl;
        // std::cout << "double : " << (double)argv[0][0] << std::endl;

        
    }
    return 0;
}