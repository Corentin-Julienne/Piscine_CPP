/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:18:02 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/15 16:55:30 by cjulienn         ###   ########.fr       */
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
	{
		this->_signed = original._signed;
	}
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

bool				Form::getSigned(void) const
{
	return this->_signed;
}

// member function AKA methods

