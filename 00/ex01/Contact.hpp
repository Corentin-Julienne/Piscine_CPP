/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:58:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 12:14:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>

class Contact
{
	public:

	Contact();
	~Contact();
	// getters and setters
	std::string		get_contact_category(int index);
	std::string		get_item(int index);
	void			set_item(std::string value, int index);
	// utils
	void			display_prompt(void);
	
	private:

	std::string		m_contact_category[5];
	std::string		m_contact_info[5];
};

#endif
