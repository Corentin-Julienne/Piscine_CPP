/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:35:06 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/12 15:20:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:

		Cat(void);
		~Cat();
		Cat(const Cat& original);

		Cat& operator=(const Cat& original);

		void makeSound(void) const;
	
	private:

		Brain	*_brain;
};

#endif
