/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:33:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/12 13:19:19 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>

// int main()
// {
//     int a;
//     double b = 5.9;
//     a = b;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "a = " << a << std::endl;  
//     return 0;
// }

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
        try {
            // Check if it's a char literal
            if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
                char c = literal[1];
                if (std::isprint(c)) {
                    std::cout << "char: '" << c << "'" << std::endl;
                    int i = static_cast<int>(c);
                    float f = static_cast<float>(c);
                    double d = static_cast<double>(c);
                    std::cout << "int: " << i << std::endl;
                    std::cout << "float: " << f << std::endl;
                    std::cout << "double: " << d << std::endl;
                } else {
                    std::cout << "Conversion to char is not displayable." << std::endl;
                }
            } else {
                // Attempt conversions for other types
                int i = std::stoi(literal);
                float f = std::stof(literal);
                double d = std::stod(literal);

                std::cout << "int: " << i << std::endl;
                std::cout << "float: " << f << std::endl;
                std::cout << "double: " << d << std::endl;

                if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
                    std::cout << "Conversion to char is not possible." << std::endl;
                } else {
                    char c = static_cast<char>(i);
                    std::cout << "char: '" << c << "'" << std::endl;
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Conversion is impossible or results in overflow: " << e.what() << std::endl;
        }
    }
};

int main(int argc, char **argv) 
{
    // ScalarConverter::convert("'a'");     // Displayable char
    // ScalarConverter::convert("42");      // int, float, double
    // ScalarConverter::convert("3.14");    // int, float, double
    // ScalarConverter::convert("-inff");   // float
    // ScalarConverter::convert("nan");     // int, float, double
    // ScalarConverter::convert("12345678901234567890");  // Overflow for int
    // ScalarConverter::convert("3.141592

    if (argc == 2)
    {
        ScalarConverter::convert(argv[0]);
        // ScalarConverter sc;
        // std::cout << "char : ";
        // sc.convert(argv[0]);
        // std::cout << "int : " << ScalarConverter::convert(argv[0]) << std::endl;
        // std::cout << "float : " << ScalarConverter::convert(argv[0]) << std::endl;
        // std::cout << "double : " << ScalarConverter::convert(argv[0]) << std::endl;
    }
}