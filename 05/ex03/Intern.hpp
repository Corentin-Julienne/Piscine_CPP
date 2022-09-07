/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/02 09:52:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include "Form.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <string>
#include <exception>

class Intern
{

	public:

		Intern(void);
		~Intern();
		Intern(const Intern& original);
		
		Intern&		operator=(const Intern& original);

		Form*		makeForm(std::string formName, std::string formTarget);

		class	InvalidNameException : public std::exception
		{
			public:
			
				const char * what() const throw();
		};
};

#endif
