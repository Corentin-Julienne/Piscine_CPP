/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:32 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:06:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

// basic constructor

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation", "test", 145, 137) {}

// constructor with params

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("Shrubbery Creation", target, 145, 137) {}

// destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// copy constructor

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original) : Form(original) {}

// overloading operator =

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	if (this != &original)
		this->Form::operator=(original);
	return *this;
}

// getters and setters

// class methods

void	ShrubberyCreationForm::action(void) const
{
	std::ofstream		dest;

	dest.open((this->getTarget() + "_shrubbery"), std::fstream::trunc);
	// draw shrubbery tree
	dest << "my-app/          " << std::endl;
	dest << "├─ node_modules/ " << std::endl;
	dest << "├─ public/       " << std::endl;
	dest << "│  ├─ favicon.ico" << std::endl;
	dest << "│  ├─ index.html " << std::endl;
	dest << "│  ├─ robots.txt " << std::endl;
	dest << "├─ src/          " << std::endl;
	dest << "│  ├─ index.css  " << std::endl;
	dest << "│  ├─ index.js   " << std::endl;
	dest << "├─ .gitignore    " << std::endl;
	dest << "├─ package.json  " << std::endl;
	dest << "├─ README.md     " << std::endl; 
	// close to avoid file leaks
	dest.close();
}
