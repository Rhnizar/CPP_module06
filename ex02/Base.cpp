/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:30:55 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/16 13:48:36 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base : destractor called" << std::endl;
}

Base* generate(void)
{
	std::srand(time(NULL));
	int ran = std::rand() % 3;
	switch(ran)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default :
			return NULL;
	}
}


void identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    identify(&p);
}
