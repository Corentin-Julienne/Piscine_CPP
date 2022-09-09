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

#include <stack>
#include <deque>
#include <iterator>

#ifndef MUTANT_STACK_CLASS
# define MUTANT_STACK_CLASS

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	
		MutantStack(void) : std::stack<T>() {}
		virtual ~MutantStack() {}

		// provide copy constructors
		MutantStack(MutantStack const &original): std::stack<T>(original) {}

		// overloading operator =

		MutantStack&	operator=(const MutantStack& original)
		{
			if (this != &original)
			{
				this->MutantStack<T>::stack::operator=(original);
			}
			return *this;
		}

		// add some iterators

		typedef	typename std::stack<T>::container_type::iterator 			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator 			begin() 
		{
			return this->MutantStack::c.begin();
		}
		iterator 			end()
		{
			return this->MutantStack::c.end();
		}
		reverse_iterator	rbegin()
		{
			return this->MutantStack::c.rbegin();
		}
		reverse_iterator	rend()
		{
			return this->MutantStack::c.rend();
		}
};

#endif
