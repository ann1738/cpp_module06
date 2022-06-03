/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:04:05 by anasr             #+#    #+#             */
/*   Updated: 2022/06/03 19:41:01 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/****************** Constructors ********************/

Data::Data()
{
	// std::cout << "Data: Default constructor is called\n";
}

Data::Data(std::string input)
{
	// std::cout << "Data: Custom constructor is called\n";
	void(Data::*f[])(std::string const &) = {&Data::itsInt, &Data::itsFloat, &Data::itsDouble, &Data::itsChar};
	bool(Data::*check[])(std::string const &) = {&Data::checkInt, &Data::checkFloat, &Data::checkDouble, &Data::checkChar};
	int index = 0;

	for (index = 0; !(this->*check[index])(input); ++index);
	if (index > 3)
		throw (convException("\e[31mType not recognized\e[0m\n"));
	(this->*f[index])(input);
	printOutput();
}

Data::Data(const Data& original)
 : c(original.c), i(original.i), f(original.f), d(original.d)
{
	// std::cout << "Data: Copy constructor is called\n";
}

Data& Data::operator=(const Data& original)
{
	// std::cout << "Data: Copy assignment overloading constructor is called\n";
	if (this != &original)
	{
		c = original.c;
		i = original.i;
		f = original.f;
		d = original.d;
	}
	return (*this);
}

/******************* Destructor *********************/

Data::~Data()
{
	// std::cout << "Data: Destructor is called\n";
}

/***************** Member Functions *****************/

/* checkers */

bool	Data::checkChar(std::string const & input)
{
	if (isprint(input[0]) && !input[1])
		return (true);
	return (false);
}

bool	Data::checkInt(std::string const & input)
{
	int i;
	for(i = 0; isdigit(input[i]); ++i);
	if (!input[i]) return (true);
	else return (false);
}

bool	Data::checkFloat(std::string const & input)
{
	int i;
	double		d = atof(input.c_str());
	if ((isnan(d) || isinf(d)))
		return (true);
	for(i = 0; isdigit(input[i]); ++i);
	if (input[i] != '.') return (false);
	for(++i; isdigit(input[i]); ++i);
	if (input[i] != 'f' || input[++i]) return (false);
	return (true);
}

bool	Data::checkDouble(std::string const & input)
{
	int i;
	for(i = 0; isdigit(input[i]); ++i);
	if (input[i] != '.') return (false);
	for(++i; isdigit(input[i]); ++i);
	if (input[i]) return (false);
	return (true);
}

/* "doers" */

void	Data::itsInt(std::string const & input)
{
	std::stringstream ss;
	std::cout << "INT\n";
	ss << input;
	ss >> i;
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}

void	Data::itsFloat(std::string const & input)
{
	std::stringstream ss;
	std::cout << "FLOAT\n";
	ss << input;
	ss >> f;
	f = static_cast<float>(atof(input.c_str()));			
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
}

void	Data::itsDouble(std::string const & input)
{
	std::stringstream ss;
	std::cout << "DOUBLE\n";
	ss << input;
	ss >> d;
	d = atof(input.c_str());
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void	Data::itsChar(std::string const & input)
{
	std::cout << "CHAR\n";
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

/* printer */

void	Data::printOutput()
{
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

