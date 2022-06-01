/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:32:44 by ann               #+#    #+#             */
/*   Updated: 2022/05/31 01:09:57 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convException.hpp"

convException::convException(std::string _msg): msg(_msg) {}

const char * convException::what() const throw() {return(this->msg.c_str());}

convException::~convException() throw() {}
