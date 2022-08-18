/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/14 15:44:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
	
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& original);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original);

		void	action(Bureaucrat const &executor) const;
	
	private:
	
		/* data */
};

#endif
