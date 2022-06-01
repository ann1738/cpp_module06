/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:37:15 by anasr             #+#    #+#             */
/*   Updated: 2022/06/01 16:00:36 by anasr            ###   ########.fr       */
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
		Base &temp = dynamic_cast<A &>(p);
		std::cout << "\e[36mIt's A\e[0m\n";
		Base temptemp(temp);
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			Base &temp = dynamic_cast<B &>(p);
			Base temptemp(temp);
			std::cout << "\e[35mIt's B\e[0m\n";
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				Base &temp = dynamic_cast<C &>(p);
				Base temptemp(temp);
				std::cout << "\e[33mIt's C\e[0m\n";
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "\e[31mIt's non of them\e[0m\n";
			}
		}
	}
}
