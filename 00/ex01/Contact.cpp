/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:58:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/01 16:35:49 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// basic constructor

Contact::Contact(void) 
{
	Contact::set_contact_categories();
}

// basic destructor

Contact::~Contact(void) 
{
	
}

// getters and setters

std::string	Contact::get_contact_category(int index)
{
	return (m_contact_category[index]);
}

void	Contact::set_contact_categories(void)
{
	this->m_contact_category[0] = "first name";
	this->m_contact_category[1] = "last name";
	this->m_contact_category[2] = "nickname";
	this->m_contact_category[3] = "phone number";
	this->m_contact_category[4] = "darkest secret";
}

std::string	Contact::get_item(int index)
{
	return (m_contact_info[index]);
}

void	Contact::set_item(std::string value, int index)
{
	m_contact_info[index] = value;
}

// utils

void	Contact::display_prompt(void)
{
	int			i;
	std::string	buf;
	
	std::cout <<  "Welcome to the contact adding tool !" << std::endl;
	std::cout << std::endl;
	i = 0;
	while (i < 5)
	{
		std::cout << "please add the " << get_contact_category(i)
		<< " of the contact, then press ENTER" << std::endl;
		std::cin >> buf;
		this->set_item(buf, i);
		i++;
	}
	std::cout << "Contact has been added" << std::endl;
}
