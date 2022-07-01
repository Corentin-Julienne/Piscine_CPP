/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:55 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 13:11:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"

Example::Example(const int num)
{
	this->_num = num << _ex_lab;
}

Example::~Example()
{
	
}

int	Example::getInt(void)
{
	return (this->_num);
}
