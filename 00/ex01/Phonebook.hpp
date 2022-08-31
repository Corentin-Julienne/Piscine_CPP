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
	void		setEntryNum(int i);
	void		setCurrentEntry(int i);
	// utils
	void		addCtctToDb(void);
	void		askForIndex(void);
	void		displayColumns(void);
	void		displayCtct(int index);
	void		displayPhonebook(void);

	private:

	int 		_entryNum;
	int			_currentEntry;
	Contact		_contacts[8];
};

#endif
