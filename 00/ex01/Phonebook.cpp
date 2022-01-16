/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/16 17:26:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>

Phonebook::Phonebook(void) : entry_num(0){
	
}

Phonebook::~Phonebook(void) {}

void	Phonebook::add_ctct_to_db(void)
{
	Contact		ctct;

	if (entry_num >= 8)
	{
		std::cout << "Welcome back to the heighties pal..." << std::endl;
		std::cout << "Only 8 contacts can be stored in this phonebook..." << std::endl;
		return ;
	}
	ctct.display_prompt();
	this->contacts[entry_num] = ctct;
	entry_num++;
}

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
		Contact ctct = this->contacts[index];
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
	int				index;
	int				i;
	std::string		item;

	std::cout << "Please ENTER the index of the contact you want to consult" << std::endl;
	std::cin >> index;
	while (index < 0 || index > entry_num - 1)
	{
		std::cout << index << " is not a valid index. Please ENTER a valid one" << std::endl;
		std::cin >> index;
	}
	std::cout << index << std::endl;
	i = 0;
	while (i < 5)
	{
		item = this->contacts[index].get_item(i);
		std::cout << item << std::endl;
 		i++;
	}
}

void	Phonebook::display_phonebook(void)
{
	int		i = 0;
	
	if (this->entry_num == 0)
	{
		std::cout << "No contact in the phonebook" <<std::endl;
		return ;
	}
	this->display_columns();
	while (i < entry_num)
	{
		this->display_ctct(i);
		i++;
	}
	this->ask_for_index();
}

void	Phonebook::display_state(void)
{
	int		i = 0;
	
	std::cout << "Entry num : " << this->entry_num << std::endl;
	while (i < this->entry_num)
	{
		std::cout << "f_n : " << this->contacts[i].get_item(0) << std::endl;
		std::cout << "l_n : " << this->contacts[i].get_item(1) << std::endl;
		std::cout << "n_n : " << this->contacts[i].get_item(2) << std::endl;
		std::cout << "p_n : " << this->contacts[i].get_item(3) << std::endl;
		std::cout << "d_s : " << this->contacts[i].get_item(4) << std::endl;
		i++;
	}
}
