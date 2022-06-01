/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:04:06 by anasr             #+#    #+#             */
/*   Updated: 2022/06/01 15:52:18 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void)
{
	Base * Ptr = NULL;
	srand(std::time(nullptr));
	switch (rand() % 10)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			Ptr = new A;
			break ;
		case 4:
		case 5:
		case 6:
			Ptr = new B;
			break ;
		case 7:
		case 8:
		case 9:
			Ptr = new C;
			break ;
	}
	return (Ptr);
}
