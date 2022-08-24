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
	this->_contactCategory[0] = "first name";
	this->_contactCategory[1] = "last name";
	this->_contactCategory[2] = "nickname";
	this->_contactCategory[3] = "phone number";
	this->_contactCategory[4] = "darkest secret";
}

// basic destructor

Contact::~Contact(void) {}

// setters and getters

std::string	Contact::getItem(int index)
{
	return (_contactInfo[index]);
}

void	Contact::setItem(std::string value, int index)
{
	_contactInfo[index] = value;
}

std::string	Contact::getContactCategory(int index)
{
	return (_contactCategory[index]);
}

// utils

void	Contact::displayPrompt(void)
{
	int			i;
	std::string	buf;
	
	std::cout <<  "Welcome to the contact adding tool !" << std::endl;
	std::cout << std::endl;
	i = 0;
	while (i < 5)
	{
		std::cout << "please add the " << this->_contactCategory[i]
		<< " of the contact, then press ENTER" << std::endl;
		std::getline(std::cin, buf);
		while (buf.empty() == true || buf.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
		{
			std::cout << "Contact info cannot be empty, please use a valid information format" << std::endl;
			std::cout << "please add the " << this->_contactCategory[i]
			<< " of the contact, then press ENTER" << std::endl;
			std::getline(std::cin, buf);
		}
		this->setItem(buf, i);
		i++;
	}
	std::cout << "Contact has been added" << std::endl;
}
