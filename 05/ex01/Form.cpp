/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:18:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 18:18:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// basic constructor

Form::Form(void) : _name("autodestruction"), _grade_sign(32), _grade_exec(13)
{
	this->_signed = false;
}

// constructor with params

Form::Form(std::string const name, unsigned int const grade_sign, unsigned int const grade_exec)
: _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 0 || grade_exec < 0)
		throw Form::GradeTooLowException();
	else if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

// destructor

Form::~Form() {}

// copy constructor

Form::Form(const Form& original) : _name(original._name), _grade_sign(original._grade_sign),
_grade_exec(original._grade_exec)
{
	this->_signed = original._signed;
}

// overloading operator =

Form&	Form::operator=(const Form& original)
{
	if (this != &original)
		this->_signed = original._signed;
	return *this;
}

// getters

std::string const	Form::getName(void) const
{
	return this->_name;
}

unsigned int const	Form::getGradeSign(void) const
{
	return this->_grade_sign;
}

unsigned int const	Form::getGradeExec(void) const
{
	return this->_grade_exec;
}

bool	Form::getSigned(void) const
{
	return this->_signed;
}

// member function

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_grade_sign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

// methods for exception handling for inside classes

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

// overloading operator <<

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	std::string		sign_status;
	
	if (form.getSigned() == true)
		sign_status = "is signed";
	else
		sign_status = "has not been signed";
	stream << "Form " << form.getName() << " requires a Bureaucrat level " << form.getGradeSign() << " or higher to be signed"
	<< " and a Bureaucrat level " << form.getGradeExec() << " to be executed. Currently, the form " << sign_status << std::endl;
	return (stream);
}
