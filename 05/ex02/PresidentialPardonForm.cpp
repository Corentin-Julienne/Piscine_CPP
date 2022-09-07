/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 18:27:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// basic constructor

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Pardon", target, 25, 5) {}

// destructor

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// constructor by copy

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : Form(original) {}

// overloading operator =

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	if (this != &original)
		this->Form::operator=(original);
	return *this;
}

// member functions

void	PresidentialPardonForm::action(void) const
{
	std::cout << "We wish to inform you that " << this->getTarget() << " has been pardonned " 
	<< "by president Zaphod Beeblebrox" << std::endl;
}
