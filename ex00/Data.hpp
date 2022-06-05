/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:00:31 by anasr             #+#    #+#             */
/*   Updated: 2022/06/05 12:28:39 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include <climits>
#include "convException.hpp"

class	Data
{
private:
	char	c;
	int		i;
	float	f;
	double	d;

	bool	iNotOk;
	bool	fNotOk;
	bool	dNotOk;
	

	bool	checkInt(std::string const & input);
	bool	checkFloat(std::string const & input);
	bool	checkDouble(std::string const & input);
	bool	checkChar(std::string const & input);

	void	itsInt(std::string const & input);
	void	itsFloat(std::string const & input);
	void	itsDouble(std::string const & input);
	void	itsChar(std::string const & input);
public:
/******************Constructors********************/
	Data();
	Data(std::string input);
	Data(const Data& original);
	Data& operator=(const Data& original);

/******************Destructor********************/
	~Data();

/******************Member Functions********************/
	void	printOutput();
};

#endif
