/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/14 15:41:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm(void);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& original);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& original);

		void	action(Bureaucrat const &executor) const;
	
	private:
		/* data */
};

#endif
