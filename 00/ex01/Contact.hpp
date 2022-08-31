/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:58:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/10 13:56:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>

class Contact
{
	public:

	Contact();
	~Contact();
	// getters and setters
	std::string		getContactCategory(int index);
	std::string		getItem(int index);
	void			setItem(std::string value, int index);
	// utils
	void			displayPrompt(void);
	
	private:

	std::string		_contactCategory[5];
	std::string		_contactInfo[5];
};

#endif
