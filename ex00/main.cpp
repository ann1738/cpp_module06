/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:27:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/03 19:36:01 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (convException("\e[31mInvalid number of arguments\e[0m\n"));
		Data data(argv[1]);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
}
