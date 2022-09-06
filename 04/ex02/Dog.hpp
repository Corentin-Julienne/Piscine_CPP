/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:11:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:54:21 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:

		Dog(void);
		~Dog();
		Dog(const Dog& original);

		Dog& operator=(const Dog& original);

		std::string		getIdeaInBrain(int index) const;
		void			setIdeaInBrain(int index);

		void makeSound(void) const;
	
	private:

		Brain		*_brain;
};

#endif
