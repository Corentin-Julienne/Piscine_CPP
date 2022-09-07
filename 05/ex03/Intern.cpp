/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:17 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:08:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// constructor

Intern::Intern(void) {}

// destructor

Intern::~Intern() {}

// methods

Form*       Intern::makeForm(std::string formName, std::string formTarget)
{
    int     i = 0;
    Form*   res = NULL;
    
    std::string	options[3] =
	{
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
    while (i < 3 && formName.compare(options[i]) != 0)
        i++;
    switch (i)
    {
        case 0:
            res = new RobotomyRequestForm(formTarget);
            break;
        case 1:
            res = new PresidentialPardonForm(formTarget);
            break;
        case 2:
            res = new ShrubberyCreationForm(formTarget);
            break;
        default:
            throw Intern::InvalidNameException();
    }
    std::cout << "intern creates " << formName << std::endl;
    return (res);
}

// exception handling

const char * Intern::InvalidNameException::what() const throw()
{
    return ("invalid form creation request");
}
