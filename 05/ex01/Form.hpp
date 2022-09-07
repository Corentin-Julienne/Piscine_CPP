/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:18:04 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 11:13:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	
		Form(void);
		Form(std::string const name, unsigned int const gradeSign, unsigned int const gradeExec);
		~Form();
		Form(const Form& original);

		Form&	operator=(const Form& original);

		// getters
		std::string const	getName(void) const;
		bool				getSigned(void) const;
		unsigned int			getGradeSign(void) const;
		unsigned int 		getGradeExec(void) const;
		// members functions
		void	beSigned(const Bureaucrat& bureaucrat);
		//  exceptions class
		class GradeTooLowException : public std::exception
		{
			public:

				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:

				const char* what() const throw();
		};
		class AlreadySignedFormException : public std::exception
		{
			public:

				const char* what() const throw();	
		};
		
	private:
	
		std::string const 	_name;
		bool				_signed;
		unsigned int const	_gradeSign;
		unsigned int const	_gradeExec;
};

std::ostream&	operator<<(std::ostream& stream, const Form& form);

#endif
