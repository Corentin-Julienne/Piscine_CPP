/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:30:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 15:37:27 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(8) {}

Span::Span(unsigned int n) : _N(n) {}

Span::~Span() {}

Span::Span(const Span& original) : _N(original._N), _vect(original._vect) {}

Span&	Span::operator=(const Span& original)
{
	if (this != &original)
	{
		this->_N = original._N;
		this->_vect = original._vect;
	}
	return *this;
}

int				Span::getByIndex(size_t index) const
{
	if (index >= this->_vect.size())
		throw InvalidIndexException();
	return (this->_vect[index]);
}

unsigned long	Span::shortestSpan(void)
{
	if (this->isSpanPossible() == false)
		throw ContainerFulfillmentNotSufficientException();
	
	long	minispan = LONG_MAX;
	long	current_diff;
	
	std::vector<int>	tmp;
	tmp = this->_vect;
	std::sort(tmp.begin(), tmp.end());

	
	std::vector<int>::iterator	current = tmp.begin();
	for (std::vector<int>::iterator	next = tmp.begin() + 1; next != tmp.end(); next++)
	{
		current_diff = std::abs(static_cast<long>(*current) - static_cast<long>(*next));
		if (current_diff < minispan)
			minispan = current_diff;
		current = next;
	}
	return (static_cast<unsigned long>(minispan));
}

unsigned long	Span::longestSpan(void)
{
	std::vector<int>	tmp;
	
	if (this->isSpanPossible() == false)
		throw ContainerFulfillmentNotSufficientException();
	
	tmp = this->_vect;
	long		min = static_cast<long>(*std::min_element(tmp.begin(), tmp.end()));
	long		max = static_cast<long>(*std::max_element(tmp.begin(), tmp.end()));
		
	return (static_cast<unsigned long>(max - min));
}

void	Span::addNumber(int num)
{
	if (this->_vect.size() <= this->_N)
		this->_vect.push_back(num);
	else
		throw ContainerIsFullException();
}

void	Span::addSeveralNumbers(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
	std::vector<int>		subvector;

	std::copy(begin, end, std::back_inserter(subvector));
	if (subvector.size() + this->_vect.size() > this->_N)
		throw ContainerCannotAddSoManyIntegersException();
	this->_vect.insert(this->_vect.end(), subvector.begin(), subvector.end());
}

bool	Span::isSpanPossible(void)
{
	if (this->_vect.size() >= 2)
		return (true);
	return (false);
}

// exception

const char * Span::ContainerIsFullException::what(void) const throw()
{
	return ("Container is full");
}

const char * Span::ContainerCannotAddSoManyIntegersException::what(void) const throw()
{
	return ("Container can't add that number of integers");
}

const char * Span::ContainerFulfillmentNotSufficientException::what(void) const throw()
{
	return ("Container is empty or have only one integer stored");
}

const char * Span::InvalidIndexException::what(void) const throw() 
{
	return ("Error: invalid index");	
}
