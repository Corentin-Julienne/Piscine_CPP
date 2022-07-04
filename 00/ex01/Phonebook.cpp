/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 15:56:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

// basic constructor

Phonebook::Phonebook(void) : m_entry_num(0), m_current_entry(0){
	
}

// basic destructor

Phonebook::~Phonebook(void) {
	
}

// setters

void	Phonebook::set_entry_num(int i)
{
	m_entry_num = i;
}

void	Phonebook::set_current_entry(int i)
{
	m_current_entry = i;
}

// utils top add contact

// this function create an obj ctct of type Contact. Display a prompt to 
// ask user to enter relevant information. store Ctct in the contact arr
// if the num of entries is sup to 8, then entry 1 (AKA the oldest)
// is replaced by the new entry

void	Phonebook::add_ctct_to_db(void)
{
	Contact		ctct;

	ctct.display_prompt();
	if (this->m_entry_num <= 7)
	{
		this->m_contacts[this->m_entry_num] = ctct;
		this->set_entry_num(this->m_entry_num + 1);
	}
	else
	{
		this->m_contacts[this->m_current_entry] = ctct;
		this->set_current_entry(this->m_current_entry + 1);
		if (this->m_current_entry > 7)
			this->set_current_entry(0);
	}
}

// utils to display contacts

// display a contact with a max width of 10

void	Phonebook::display_columns(void)
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
		std::cout << ctct.get_contact_category(i);
		std::cout << '|';
		i++;
	}
	std::cout << std::endl;
}

void	Phonebook::display_ctct(int index)
{	
	int			i;
	std::string	contact_info;

	std::cout << std::setw(10);
	std::cout << index;
	std::cout << '|';
	i = 0;
	while (i < 3)
	{
		Contact ctct = this->m_contacts[index];
		contact_info.assign(ctct.get_item(i));
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

void	Phonebook::ask_for_index(void)
{
	int					index;
	int					i;
	std::string			item;
	std::string			category;
	std::stringstream	ss;

	std::cout << "Please ENTER the index of the contact you want to consult" << std::endl;
	std::getline(std::cin, item);
	while (item.size() != 1 || item[0] < '0' || item[0] > ((m_entry_num - 1) + '0'))
	{
		std::cout << item << " is not a valid index. Please ENTER a valid one" << std::endl;
		std::getline(std::cin, item);
	}
	ss << item;
	ss >> index;
	i = 0;
	while (i < 5)
	{
		category = this->m_contacts[index].get_contact_category(i);
		item = this->m_contacts[index].get_item(i);
		std::cout << category << " : " << item << std::endl;
 		i++;
	}
}

void	Phonebook::display_phonebook(void)
{
	int		i = 0;
	
	if (this->m_entry_num == 0)
	{
		std::cout << "No contact in the phonebook" <<std::endl;
		return ;
	}
	this->display_columns();
	while (i < m_entry_num)
	{
		this->display_ctct(i);
		i++;
	}
	this->ask_for_index();
}
