/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 15:20:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// constructor

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request", 72, 45) {}

// destructor

RobotomyRequestForm::~RobotomyRequestForm() {}

// copy constructor

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
{
	
}

// overloading operator =

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	
}

// getters and setters

// class methods

void	RobotomyRequestForm::action(void) const
{
	int		randomizer;
	
	std::cout << "[LOUD DRILLING NOISE !!!]" << std::endl;
	randomizer = rand() % 100;
	if (randomizer < 50)
		std::cout << "Sorry, but unfortunately the robotomy failed" << std::endl;
	else
		std::cout << "We inform you that the robotomy was performed succesfully on " << this->getTarget() << std::endl;
}
