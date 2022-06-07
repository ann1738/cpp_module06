/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:40 by anasr             #+#    #+#             */
/*   Updated: 2022/06/07 08:17:00 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"

int	main(void)
{
	Base *newBase;
	
	std::srand(std::time(0));
	for (int i = 0; i < 10; ++i)
	{
		newBase = generate();
		identify(newBase);
		identify(*newBase);
		delete newBase;
	}
}
