/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:30:50 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/29 16:06:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <string>
#include <vector>

class Span
{
	public:

		Span(void);
		Span(unsigned int n);
		~Span();
		Span(const Span& original);

		Span&		operator=(const Span& original);
		
		void			addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
	private:

		unsigned int	N;
};

#endif
