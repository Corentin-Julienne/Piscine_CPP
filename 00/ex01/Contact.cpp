/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:58:56 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 15:51:28 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// basic constructor

Contact::Contact(void) 
{
	this->_contact_category[0] = "first name";
	this->_contact_category[1] = "last name";
	this->_contact_category[2] = "nickname";
	this->_contact_category[3] = "phone number";
	this->_contact_category[4] = "darkest secret";
}

// basic destructor

Contact::~Contact(void) {}

// setters and getters

std::string	Contact::get_item(int index)
{
	return (_contact_info[index]);
}

void	Contact::set_item(std::string value, int index)
{
	_contact_info[index] = value;
}

std::string	Contact::get_contact_category(int index)
{
	return (_contact_category[index]);
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
		std::cout << "please add the " << this->_contact_category[i]
		<< " of the contact, then press ENTER" << std::endl;
		std::getline(std::cin, buf);
		while (buf.empty() == true || buf.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		{
			std::cout << "Contact info cannot be empty, please use a valid information format" << std::endl;
			std::cout << "please add the " << this->_contact_category[i]
			<< " of the contact, then press ENTER" << std::endl;
			std::getline(std::cin, buf);
		}
		this->set_item(buf, i);
		i++;
	}
	std::cout << "Contact has been added" << std::endl;
}
