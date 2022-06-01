/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:24:54 by anasr             #+#    #+#             */
/*   Updated: 2022/06/01 16:01:02 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_HPP
# define SHARED_HPP

#include "A.hpp"
#include "Base.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base *	generate(void);
void 	identify(Base* p);
void 	identify(Base& p);

#endif