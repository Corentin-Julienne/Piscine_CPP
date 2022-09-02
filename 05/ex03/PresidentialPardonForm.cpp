/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:24 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:05:46 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// basic constructor

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("Presidential Pardon", target, 25, 5) {}

// destructor

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// constructor by copy

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original)
{
	
}

// overloading operator =

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	
}

// member functions

void	PresidentialPardonForm::action(void) const
{
	std::cout << "We wish to inform you that " << this->getTarget() << " has been pardonned " 
	<< "by president Zaphod Beeblebrox" << std::endl;
}
