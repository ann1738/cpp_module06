/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:27:21 by ann               #+#    #+#             */
/*   Updated: 2022/06/01 10:17:34 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include "convException.hpp"

/* THIS IS BY NO MEANS DONE PLS REWRITE THE CODE (account for numeric limits, overflow) */

bool	checkChar(char **argv)
{
	if (isprint(argv[1][0]) && !argv[1][1])
		return (true);
	return (false);
}

bool	checkInt(char **argv)
{
	int i;
	for(i = 0; isdigit(argv[1][i]); ++i);
	if (!argv[1][i]) return (true);
	else return (false);
}

bool	checkFloat(char **argv)
{
	int i;
	double		d = atof(argv[1]);
	if ((isnan(d) || isinf(d)))
		return (true);
	for(i = 0; isdigit(argv[1][i]); ++i);
	if (argv[1][i] != '.') return (false);
	for(++i; isdigit(argv[1][i]); ++i);
	if (argv[1][i] != 'f' || argv[1][++i]) return (false);
	return (true);
}

bool	checkDouble(char **argv)
{
	int i;
	for(i = 0; isdigit(argv[1][i]); ++i);
	if (argv[1][i] != '.') return (false);
	for(++i; isdigit(argv[1][i]); ++i);
	if (argv[1][i]) return (false);
	return (true);
}


int	main(int argc, char **argv)
{
	char	c;
	int		i;
	float	f;
	double	d;
	try
	{
		if (argc != 2) throw (convException("\e[31mInvalid number of arguments\e[0m\n"));
		if (checkInt(argv))
		{
			std::cout << "INT\n";
			i = atoi(argv[1]);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
		else if (checkFloat(argv))
		{
			std::cout << "FLOAT\n";
			f = static_cast<float>(atof(argv[1]));			
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		}
		else if (checkDouble(argv))
		{
			std::cout << "DOUBLE\n";
			d = atof(argv[1]);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		}
		else if (checkChar(argv))
		{
			std::cout << "CHAR\n";
			c = argv[1][0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		else
			throw (convException("\e[31mType not recognized\e[0m\n"));
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: " << "Non Displayable" << std::endl;
		if (isnan(d) || isinf(d))
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		if (f - floor(f) == 0)
		{
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
}