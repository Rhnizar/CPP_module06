/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStatic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:43:16 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/14 21:09:23 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

class StaticTest
{
	private:
		static int rr;
	public:
		StaticTest(int r){rr = r;}
		int	getrr(){ return rr;}
		static void yy() {std::cout << "rida";}
};
int StaticTest::rr = 0;
int main()
{
	StaticTest st1(5);
	std::cout << st1.getrr() << std::endl;

	StaticTest::yy();
	return 0;
}