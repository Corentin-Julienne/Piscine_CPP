/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:28:59 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 12:05:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
	
		WrongAnimal(void);
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& original);

		WrongAnimal& operator=(const WrongAnimal& original);

		std::string	getType(void) const;
		void		makeSound(void) const;
		
	protected:
	
		std::string 	_type;
};

#endif
