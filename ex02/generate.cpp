/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:04:06 by anasr             #+#    #+#             */
/*   Updated: 2022/06/07 08:16:20 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"

Base * generate(void)
{
	Base * Ptr = NULL;
	switch (std::rand() % 10)
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
