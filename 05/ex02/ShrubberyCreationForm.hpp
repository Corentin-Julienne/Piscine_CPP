/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 12:45:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

#include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
	
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& original);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original);

		void	action(void) const;
	
};

#endif
