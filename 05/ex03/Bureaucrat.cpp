/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:06 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:04:54 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// basic constructor

Bureaucrat::Bureaucrat(void) : _name("Agent 47"), _grade(1) {}
	
// constructor with params

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// methods for exception handling for inside classes

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::FormNotSignedException::what() const throw()
{
	return ("To be executed, a form must previously be signed");
}

// overloading operator <<

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (stream);
}
