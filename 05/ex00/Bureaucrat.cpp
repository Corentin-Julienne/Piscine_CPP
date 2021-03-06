/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:18:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/15 16:50:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// basic constructor

Bureaucrat::Bureaucrat(void) : _name("Agent 47"), _grade(1) {}
	
// constructor with params

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

// basic destructor

Bureaucrat::~Bureaucrat(void) {}

// constructor by copy

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade)
{
	this->_grade = original._grade;
}

// overloading assignement operator (unable to change const std::string _name)

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& original)
{
	if (this != &original)
		this->_grade = original._grade;
	return *this;
}

// getters

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->_grade;
} 

// methods

void	Bureaucrat::decrementGrade(Bureaucrat& target)
{
	if (target._grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		target._grade++;
}

void	Bureaucrat::incrementGrade(Bureaucrat& target)
{
	if (target._grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		target._grade--;
}

// methods for exception handling for inside classes

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low [grade can vary between 1 and 150]");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high [grade can vary between 1 and 150]");
}

// overloading operator <<

std::ostream&	operator<<(const std::ostream& stream, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
}
