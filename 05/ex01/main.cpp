/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:13:19 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 11:37:49 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	stalin("Comrade Stalin", 1);
	Bureaucrat	trotsky("Comrade Trotsky", 150);

	Form		gulag("Gulag Emprisonment Form", 17, 4);
	Form		execution("Death Sentence Form", 85, 68);

	// comrade Stalin want to send someone to gulag (should work)
	try {
		gulag.beSigned(stalin);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	stalin.signForm(gulag);
	// comrade Trotsky want to give an execution order (should trigger exception)
	try {
		execution.beSigned(trotsky);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	trotsky.signForm(execution);
	return (0);
}
