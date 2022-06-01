/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:54:07 by anasr             #+#    #+#             */
/*   Updated: 2022/06/01 13:26:13 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <exception>


int	main(void)
{
	Data *data = new Data;
	uintptr_t newPtr;

	std::cout << "\e[32mThe Data object BEFORE serializing and deserializing\e[0m\n";
	data->printData();

	newPtr = serialize(data);
	data = deserialize(newPtr);

	std::cout << "\e[32mThe copy Data object AFTER serializing and deserializing\e[0m\n";
	data->printData();

	delete data;
}
