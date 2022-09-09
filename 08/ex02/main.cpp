/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:49:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/04 19:56:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <stack>
#include <deque>
#include <list>
#include <vector>

int main(void)
{
	std::cout << "testing with Mutanstack and deque" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	
	MutantStack<int> mstack;
	std::deque<int>	 deq;

	//----------------------------//
	mstack.push(5);
	mstack.push(17);
	//----------------------------//
	deq.push_back(5);
	deq.push_back(17);
	//----------------------------//

	std::cout << "comparing output from deque and mutantstack" << std::endl;
	std::cout << "mutantstack.top() = " << mstack.top() << " and deque.back() [.top() equivalency] = " << deq.back() << std::endl;
	std::cout << "---------------------------------" << std::endl;

	// we pop a value
	mstack.pop();
	deq.pop_back();


	std::cout << "print the size of the mutantstack and the deque [should be 1 in both cases as we had pop one element]" << std::endl;
	std::cout << "Mutantstack size = " << mstack.size() << " and deque size = " << deq.size() << std::endl;

	// pushing some values again
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	//---------------------------//
	deq.push_back(3);
	deq.push_back(5);
	deq.push_back(737);
	deq.push_back(0);
	//---------------------------//

	std::cout << "check if iterators work well" << std::endl;
	//---------------------------//
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	//---------------------------//
	std::deque<int>::iterator	it_deq = deq.begin();
	std::deque<int>::iterator	ite_deq = deq.end();
	//---------------------------//

	std::cout << "displaying mutantstack" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "displaying deque" << std::endl;
	++it_deq;
	--it_deq;
	while (it_deq != ite_deq)
	{
		std::cout << *it_deq << std::endl;
		++it_deq;
	}
	
	//-----------------------------------------------------------------------------//

	//-----------------------------------------------------------------------------//


	std::cout << "testing with Mutanstack and VECTOR" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	
	MutantStack<int> 		mstack2;
	std::vector<int>	 	vect;

	//----------------------------//
	mstack2.push(5);
	mstack2.push(17);
	//----------------------------//
	vect.push_back(5);
	vect.push_back(17);
	//----------------------------//

	std::cout << "comparing output from vector and mutantstack" << std::endl;
	std::cout << "mutantstack.top() = " << mstack2.top() << " and vector.back() [.top() equivalency] = " << vect.back() << std::endl;
	std::cout << "---------------------------------" << std::endl;

	// we pop a value
	mstack2.pop();
	vect.pop_back();


	std::cout << "print the size of the mutantstack and the vector [should be 1 in both cases as we had pop one element]" << std::endl;
	std::cout << "Mutantstack size = " << mstack2.size() << " and vector size = " << vect.size() << std::endl;

	// pushing some values again
	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);
	mstack2.push(0);
	//---------------------------//
	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(737);
	vect.push_back(0);
	//---------------------------//

	std::cout << "check if iterators work well" << std::endl;
	//---------------------------//
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	//---------------------------//
	std::vector<int>::iterator	it_vect = vect.begin();
	std::vector<int>::iterator	ite_vect = vect.end();
	//---------------------------//

	std::cout << "displaying mutantstack" << std::endl;
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "displaying vector" << std::endl;
	++it_vect;
	--it_vect;
	while (it_vect != ite_vect)
	{
		std::cout << *it_vect << std::endl;
		++it_vect;
	}

	
	//-----------------------------------------------------------------------------//

	//-----------------------------------------------------------------------------//
	
	
	std::cout << "testing with Mutanstack and LIST" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	
	MutantStack<int> 		mstack3;
	std::list<int>	 		list;

	//----------------------------//
	mstack3.push(5);
	mstack3.push(17);
	//----------------------------//
	list.push_back(5);
	list.push_back(17);
	//----------------------------//

	std::cout << "comparing output from list and mutantstack" << std::endl;
	std::cout << "mutantstack.top() = " << mstack3.top() << " and list.back() [.top() equivalency] = " << list.back() << std::endl;
	std::cout << "---------------------------------" << std::endl;

	// we pop a value
	mstack3.pop();
	list.pop_back();

	std::cout << "print the size of the mutantstack and the list [should be 1 in both cases as we had pop one element]" << std::endl;
	std::cout << "Mutantstack size = " << mstack3.size() << " and vector size = " << list.size() << std::endl;

	// pushing some values again
	mstack3.push(3);
	mstack3.push(5);
	mstack3.push(737);
	mstack3.push(0);
	//---------------------------//
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	//---------------------------//

	std::cout << "check if iterators work well" << std::endl;
	//---------------------------//
	MutantStack<int>::iterator it3 = mstack3.begin();
	MutantStack<int>::iterator ite3 = mstack3.end();
	//---------------------------//
	std::list<int>::iterator	it_list = list.begin();
	std::list<int>::iterator	ite_list = list.end();
	//---------------------------//

	std::cout << "displaying mutantstack" << std::endl;
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::cout << "displaying list" << std::endl;
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	
	//---------------------------------------//

	//---------------------------------------//

	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "A few additional tests" << std::endl << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	std::cout << "checking reverse iterators with Mutanstack and map"<< std::endl;

	//---------------------------//
	MutantStack<int>::reverse_iterator r_it3 = mstack3.rbegin();
	MutantStack<int>::reverse_iterator r_ite3 = mstack3.rend();
	//---------------------------//
	std::list<int>::reverse_iterator	r_it_list = list.rbegin();
	std::list<int>::reverse_iterator	r_ite_list = list.rend();
	//---------------------------//

	std::cout << "displaying reverse mutantstack" << std::endl;
	++r_it3;
	--r_it3;
	while (r_it3 != r_ite3)
	{
		std::cout << *r_it3 << std::endl;
		++r_it3;
	}
	std::cout << "displaying reverse list" << std::endl;
	++r_it_list;
	--r_it_list;
	while (r_it_list != r_ite_list)
	{
		std::cout << *r_it_list << std::endl;
		++r_it_list;
	}

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "test assignment overloading a copy constructor" << std::endl;

	MutantStack<int>  cpy(mstack3);

	std::cout << "Element at the top of original is : " << mstack3.top() << " and element at the top of copy is : " << cpy.top() << std::endl;

	MutantStack<int>	cpy_2;

	cpy_2 = mstack3;

	std::cout << "Element at the top of original is : " << mstack3.top() << " and element at the top of copy is : " << cpy_2.top() << std::endl;


	//--------------------------------------//
	// verif leaks
	//system("leaks Mutation");
	return (0);
}
