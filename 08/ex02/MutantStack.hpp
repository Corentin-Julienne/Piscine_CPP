/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:49:30 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 22:21:49 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_CLASS
# define MUTANT_STACK_CLASS

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		MutantStack(void) : std::stack<T>() {}
		virtual ~MutantStack();
		

		// add some iterators

		typedef	typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void) {return std::stack<T>::c);}
		iterator end(void) {return std::stack<T>::c);}
};

#endif
