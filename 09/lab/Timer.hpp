/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:38:55 by cjulienn          #+#    #+#             */
/*   Updated: 2023/03/19 11:54:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>

struct Timer
{
	Timer(std::string clockName);
	~Timer();
	
	std::chrono::time_point<std::chrono::steady_clock> 	start, end;
	std::chrono::duration<float>						duration;	
	std::string											_clockName;	
};
