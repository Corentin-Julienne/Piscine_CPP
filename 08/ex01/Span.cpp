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

unsigned int	Span::shortestSpan(void)
{
	std::vector<int>	tmp;
	std::vector<int>	result;
	
	if (this->isSpanPossible() == false)
		throw ContainerFulfillmentNotSufficientException();
	tmp = this->_vect;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(result));
	return (*std::min_element(result.begin(), result.end()));
}

unsigned int	Span::longestSpan(void)
{
	std::vector<int>	tmp;
	std::vector<int>	result;
	
	if (this->isSpanPossible() == false)
		throw ContainerFulfillmentNotSufficientException();
	tmp = this->_vect;
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(result));
	return (*std::max_element(result.begin(), result.end()));
}

void	Span::addNumber(int num)
{
	if (this->_vect.size() <= 7)
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
