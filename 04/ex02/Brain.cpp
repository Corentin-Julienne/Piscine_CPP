/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:10:55 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/06 20:53:12 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// constructor (initiating also brain with random ideas)

Brain::Brain(void)
{
	// initiating an array of ideas
	std::string		ideas_pool[] = {
		"Eat",
		"Socialize",
		"Defend Territory",
		"Hunting",
		"Reproduce",
		"Drink"
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas_pool[rand() % 6];
	std::cout << "Brain Constructor has been called !" << std::endl;
}

// destructor

Brain::~Brain()
{
	std::cout << "Brain Destructor has been called !" << std::endl;
}

// constructor by copy

Brain::Brain(const Brain& original)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = original._ideas[i];
	std::cout << "Brain Constructor by Copy has been called !" << std::endl;
}

// overloading operator =

Brain&	Brain::operator=(const Brain& original)
{
	std::cout << "Operator = has been called on object of type Brain" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = original._ideas[i];
	}
	return *this;
}

std::string		Brain::getIdea(int index) const
{
	std::string 	res = this->_ideas[index];
	return (res);
}

void			Brain::setIdea(int index)
{
	this->_ideas[index] = "I Hate C++ Syntax !!!";
}
