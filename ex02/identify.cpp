/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:37:15 by anasr             #+#    #+#             */
/*   Updated: 2022/06/07 08:09:59 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "\e[36mIt's A\e[0m\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "\e[35mIt's B\e[0m\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "\e[33mIt's C\e[0m\n";
	else
		std::cout << "\e[31mIt's non of them\e[0m\n";
}

void identify(Base& p)
{
	try
	{
		Base temp = dynamic_cast<A &>(p);
		std::cout << "\e[36mIt's A\e[0m\n";
	}
	catch(const std::exception & e)
	{
		try
		{
			Base temp = dynamic_cast<B &>(p);
			std::cout << "\e[35mIt's B\e[0m\n";
		}
		catch(const std::exception & e)
		{
			try
			{
				Base temp = dynamic_cast<C &>(p);
				std::cout << "\e[33mIt's C\e[0m\n";
			}
			catch(const std::exception & e)
			{
				std::cout << "\e[31mIt's non of them\e[0m\n";
			}
		}
	}
}
