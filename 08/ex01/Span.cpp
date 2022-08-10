/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:30:48 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/29 16:05:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(8) {}

Span::Span(unsigned int n) : N(n) {}

Span::~Span() {}

Span::Span(const Span& original) : N(original.N) {}

Span&	Span::operator=(const Span& original)
{
	if (this != &original)
		this->N = original.N;
	return *this;
}

void	Span::addNumber(int num)
{
		
}

