/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:23:40 by anasr             #+#    #+#             */
/*   Updated: 2022/06/01 16:00:49 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.hpp"

int	main(void)
{
	Base *newBase;

	newBase = generate();
	identify(newBase);
	identify(*newBase);
	delete newBase;
}