/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:22 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 13:18:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"
# include <iostream>

int main(void)
{
	Example	example(456);
	std::cout << example._num << std::endl;	
	return (0);
}
