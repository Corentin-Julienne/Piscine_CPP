/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:05:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/16 16:54:21 by cjulienn         ###   ########.fr       */
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
	void		add_ctct_to_db(void);
	void		ask_for_index(void);
	void		display_columns(void);
	void		display_ctct(int index);
	void		display_phonebook(void);
	void		display_state(void);
	
	private:

	int 		entry_num;
	Contact		contacts[8];
};

#endif
