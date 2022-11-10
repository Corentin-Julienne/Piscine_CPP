/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 13:57:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <cstdio>

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	// getters and setters
	void		set_entry_num(int i);
	void		set_current_entry(int i);
	// utils
	void		add_ctct_to_db(void);
	void		ask_for_index(void);
	void		display_columns(void);
	void		display_ctct(int index);
	void		display_phonebook(void);

	private:

	int 		_entry_num;
	int			_current_entry;
	Contact		_contacts[8];
};

#endif
