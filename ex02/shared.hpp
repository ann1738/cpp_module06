/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:24:54 by anasr             #+#    #+#             */
/*   Updated: 2022/06/07 08:15:42 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_HPP
# define SHARED_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <ctime>
#include <cstdlib>

Base *	generate(void);
void 	identify(Base* p);
void 	identify(Base& p);

#endif