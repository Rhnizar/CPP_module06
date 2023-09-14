/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:30:07 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/15 00:33:26 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib> // Include the header for rand()

class Base
{
	public:
		virtual ~Base();
		Base* generate(void);
		void identify(Base* p);
		void identify(Base& p);
};


#endif