/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/04 12:24:11 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_PHONEBOOK
# define DEF_PHONEBOOK

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <cstdio>

class Phonebook
{
	public:

	Phonebook();
	~Phonebook();
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

	int 		m_entry_num;
	int			m_current_entry;
	Contact		m_contacts[8];
};

#endif
