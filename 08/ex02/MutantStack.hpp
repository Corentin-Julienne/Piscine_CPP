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
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	
		MutantStack(void) : std::stack<T, Container>() {}
		virtual ~MutantStack();
		MutantStack(const MutantStack<T, Container>& original) : MutantStack<T, Container>::stack(original) {}

		MutantStack<T, Container>& operator=(const MutantStack<T, Container>& rhs)
		{
			if (this != &rhs)
				this->MutantStack<T, Container>::stack::operator=(rhs);
			return *this;
		}
		
		// add some iterators

		typedef	typename Container::iterator 			iterator;
		typedef typename Container::reverse_iterator	reverse_iterator;

		iterator 			begin() 
		{
			return this->c. ;
		}
		iterator 			end()
		{
			return this->c.end();
		}
		reverse_iterator	rbegin()
		{
			return this->c.rbegin();
		}
		reverse_iterator	rend()
		{
			return this->c.rend();
		}
};

#endif
