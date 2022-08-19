/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 15:22:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// basic constructor

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon", 25, 5) {}

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
	std::cout << "We wish you to inform that " << this->getTarget() << " has been pardonned " 
	<< "by president Zaphod Beeblebrox" << std::endl;
}
