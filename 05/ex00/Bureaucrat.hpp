/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:19:00 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 17:22:51 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
	
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& original);

		Bureaucrat&	operator=(const Bureaucrat& original);
		// getters
		unsigned int	getGrade(void) const;
		std::string		getName(void) const;
		// methods
		void		decrementGrade(void);
		void		incrementGrade(void);
		// inside classes for exception handling
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

	private:
	
		std::string const 	_name;
		unsigned int		_grade;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif
