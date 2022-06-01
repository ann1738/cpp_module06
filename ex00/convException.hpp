/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convException.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:29:31 by ann               #+#    #+#             */
/*   Updated: 2022/05/31 01:09:11 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVEXCEPTION_HPP
# define CONVEXCEPTION_HPP

#include <exception>
#include <string>

class convException: public std::exception
{
private:
	std::string	msg;
public:
	convException(std::string _msg);
	const char* what() const throw();
	~convException() throw();
};

#endif