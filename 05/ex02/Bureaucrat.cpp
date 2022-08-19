/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:43 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 16:45:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

// basic constructor

Bureaucrat::Bureaucrat(void) : _name("Agent 47"), _grade(1) {}
	
// constructor with params

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	if (grade < 1)
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

void	Bureaucrat::signForm(const Form& form)
{
	if (form.getSigned() == true)
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	else
	{
		std::cout << this->_name << " could not sign " << form.getGradeExec() << " because required grade is "
		<< form.getGradeSign() << " and " << this->_name << " got a grade of " << this->_grade  << std::endl;
	}
}

void	Bureaucrat::executeForm(const Form& form)
{
	
	
	// to implement
	if (form.getSigned() == false)
		throw Bureaucrat::FormNotSignedException();
	else if (this->_grade <= form.getGradeExec())
	{
		// exec the form
		form.action();
		// print feedback msg
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
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
