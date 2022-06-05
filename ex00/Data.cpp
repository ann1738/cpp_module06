/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:04:05 by anasr             #+#    #+#             */
/*   Updated: 2022/06/05 13:05:05 by ann              ###   ########.fr       */
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
	iNotOk = false;
	void(Data::*f[])(std::string const &) = {&Data::itsInt, &Data::itsFloat, &Data::itsDouble, &Data::itsChar};
	bool(Data::*check[])(std::string const &) = {&Data::checkInt, &Data::checkFloat, &Data::checkDouble, &Data::checkChar};
	int index = 0;

	for (index = 0; index < 4 && !(this->*check[index])(input); ++index);
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
	int i = 0;
	if (input[i] == '+' || input[i] == '-') ++i;
	for(; isdigit(input[i]); ++i);
	if (!input[i]) return (true);
	else return (false);
}

bool	Data::checkFloat(std::string const & input)
{
	/* checking special numeric limits */
	double		f = atof(input.c_str());
	if ((isnan(f) || isinf(f)) && input[3] == 'f')
	{	
		if ((input.compare(0, 4, "nanf") || input.compare(0, 4, "inff")) && input[4]) return (false);
		if (((input.compare(0, 3, "nan") && !input.compare("nanf")) || (input.compare(0, 3, "inf") && !input.compare("inff"))) && input[3]) return (false);
		return (true);
	}

	int i = 0;
	if (input[i] == '+' || input[i] == '-') ++i;
	for(; isdigit(input[i]); ++i);
	if (input[i] != '.') return (false);
	for(++i; isdigit(input[i]); ++i);
	if (input[i] != 'f' || input[++i]) return (false);
	return (true);
}

bool	Data::checkDouble(std::string const & input)
{
	/* checking special numeric limits */
	double		d = atof(input.c_str());
	if ((isnan(d) || isinf(d)))
	{
		if ((input.compare(0, 4, "nanf") || input.compare(0, 4, "inff")) && input[4]) return (false);
		if ((input.compare(0, 3, "nan") || input.compare(0, 3, "inf")) && input[3]) return (false);
		return (true);
	}

	int i = 0;
	if (input[i] == '+' || input[i] == '-') ++i;
	for(; isdigit(input[i]); ++i);
	if (input[i] != '.') return (false);
	for(++i; isdigit(input[i]); ++i);
	if (input[i]) return (false);
	return (true);
}

/* "doers" */

void	Data::itsInt(std::string const & input)
{
	std::cout << "INT\n";
	std::stringstream ss;
	ss << input;
	if (!(ss >> i)) throw convException("\e[31mInvalid integer underflow/overflow\e[0m\n");
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}

void	Data::itsFloat(std::string const & input)
{
	std::cout << "FLOAT\n";
	std::stringstream ss;
	long long	iCheck;
	ss << input;
	ss >> f;
	f = static_cast<float>(atof(input.c_str()));		
	c = static_cast<char>(f);
	iCheck = static_cast<long long>(f);
	std::cout << iCheck << std::endl;
	if ((iCheck > INT_MAX || iCheck < INT_MIN))	iNotOk = true;
	i = static_cast<int>(f);
	d = static_cast<double>(f);
}

void	Data::itsDouble(std::string const & input)
{
	std::cout << "DOUBLE\n";
	std::stringstream ss;
	long long	iCheck;
	ss << input;
	ss >> d;
	d = atof(input.c_str());
	c = static_cast<char>(d);
	iCheck = static_cast<long long>(f);
	std::cout << iCheck << std::endl;
	if ((iCheck > INT_MAX || iCheck < INT_MIN))	iNotOk = true;
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void	Data::itsChar(std::string const & input)
{
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
	if (isnan(d) || isinf(d) || iNotOk)
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

