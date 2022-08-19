/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/19 15:16:32 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"

#include <cstdlib>

class RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm(void);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& original);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& original);

		void	action(void) const;
	
	private:
		/* data */
};

#endif
