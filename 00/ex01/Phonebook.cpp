/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 15:50:54 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

// basic constructor

PhoneBook::PhoneBook(void) : _entryNum(0), _currentEntry(0) {}

// basic destructor

PhoneBook::~PhoneBook(void) {}

// setters

void	PhoneBook::setEntryNum(int i)
{
	_entryNum = i;
}

void	PhoneBook::setCurrentEntry(int i)
{
	_currentEntry = i;
}

// utils top add contact

// this function create an obj ctct of type Contact. Display a prompt to 
// ask user to enter relevant information. store Ctct in the contact arr
// if the num of entries is sup to 8, then entry 1 (AKA the oldest)
// is replaced by the new entry

void	PhoneBook::addCtctToDb(void)
{
	Contact		ctct;

	ctct.displayPrompt();
	if (this->_entryNum <= 7)
	{
		this->_contacts[this->_entryNum] = ctct;
		this->setEntryNum(this->_entryNum + 1);
	}
	else
	{
		this->_contacts[this->_currentEntry] = ctct;
		this->setCurrentEntry(this->_currentEntry + 1);
		if (this->_currentEntry > 7)
			this->setCurrentEntry(0);
	}
}

// utils to display contacts

// display a contact with a max width of 10

void	PhoneBook::displayColumns(void)
{
	Contact	ctct;
	int		i;

	std::cout << std::setw(10);
	std::cout << "index";
	std::cout << '|';
	i = 0;
	while (i < 3)
	{
		std::cout << std::setw(10);
		std::cout << ctct.getContactCategory(i);
		std::cout << '|';
		i++;
	}
	std::cout << std::endl;
}

void	PhoneBook::displayCtct(int index)
{	
	int			i;
	std::string	contact_info;

	std::cout << std::setw(10);
	std::cout << index;
	std::cout << '|';
	i = 0;
	while (i < 3)
	{
		Contact ctct = this->_contacts[index];
		contact_info.assign(ctct.getItem(i));
		if (contact_info.size() > 10)
		{
			contact_info[9] = '.';
			contact_info = contact_info.substr(0, 10);
		}
		std::cout << std::setw(10);
		std::cout << contact_info;
		std::cout << '|';
		i++;
	}
	std::cout << std::endl;
}

void	PhoneBook::askForIndex(void)
{
	int					index;
	int					i;
	std::string			item;
	std::string			category;
	std::stringstream	ss;

	std::cout << "Please ENTER the index of the contact you want to consult" << std::endl;
	std::getline(std::cin, item);
	while (item.size() != 1 || item[0] < '0' || item[0] > ((_entryNum - 1) + '0'))
	{
		std::cout << item << " is not a valid index. Please ENTER a valid one" << std::endl;
		std::getline(std::cin, item);
	}
	ss << item;
	ss >> index;
	i = 0;
	while (i < 5)
	{
		category = this->_contacts[index].getContactCategory(i);
		item = this->_contacts[index].getItem(i);
		std::cout << category << " : " << item << std::endl;
 		i++;
	}
}

void	PhoneBook::displayPhonebook(void)
{
	int		i = 0;
	
	if (this->_entryNum == 0)
	{
		std::cout << "No contact in the PhoneBook" <<std::endl;
		return ;
	}
	this->displayColumns();
	while (i < _entryNum)
	{
		this->displayCtct(i);
		i++;
	}
	this->askForIndex();
}
