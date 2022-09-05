/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:30:50 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 15:18:05 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>

class Span
{
	public:

		Span(void);
		Span(unsigned int n);
		~Span();
		Span(const Span& original);

		Span&		operator=(const Span& original);

		void			addNumber(int num);
		void			addSeveralNumbers(const std::vector<int>::iterator &begin,
						 const std::vector<int>::iterator &end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		// utils

		bool			isSpanPossible(void);

		// exception handling
		class	ContainerIsFullException : public std::exception
		{
			public:
			
				const char * what() const throw();
		};
		class	ContainerCannotAddSoManyIntegersException : public std::exception
		{
			public:

				const char * what() const throw();	
		};
		class	ContainerFulfillmentNotSufficientException : public std::exception
		{
			public:

				const char * what() const throw();	
		};
	
	private:

		unsigned int		_N;
		std::vector<int>	_vect;
};

#endif
