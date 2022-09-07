/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:28 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:06:16 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// basic constructor

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request", "Specimen", 72, 45) {}

// constructor with params

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("Robotomy Request", target, 72, 45) {}

// destructor

RobotomyRequestForm::~RobotomyRequestForm() {}

// copy constructor

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original) : Form(original) {}

// overloading operator =

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	if (this != &original)
		this->Form::operator=(original);
	return *this;
}

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
