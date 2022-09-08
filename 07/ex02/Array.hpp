/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 09:18:21 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/03 11:57:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_CLASS_HPP
#define ARRAY_CLASS_HPP

#include <exception>

template <typename T>
class Array
{
	public:
	
		// basic constructor
		Array(void) {};
		// constructor with array size
		Array(unsigned int n) : _arrSize(n)
		{
			this->_arrType = new T[n];
		}
		// destructor
		~Array()
		{
			delete[] this->_arrType;
		}
		// constructor by copy
		Array(const Array& original) : _arrSize(original._arrSize)
		{
			this->_arrType = new T[original._arrSize];
			for (unsigned int i = 0; i < original._arrSize; i++)
				this->_arrType[i] = original._arrType[i];
		}
		// overloading operator =
		Array&	operator=(const Array& original)
		{
			if (this != &original)
			{
				this->_arrSize = original._arrSize;
				this->_arrType = new T[original._arrSize];
				for (unsigned int i = 0; i < original._arrSize; i++)
					this->_arrType[i] = original._arrType[i];
			}
			return *this;
		}
		// overloading operator []
		T&		operator[](unsigned int index)
		{
			if (index >= this->_arrSize)
				throw InvalidIndexException();
			else
				return this->_arrType[index];
		}
		// getter (size function)
		unsigned int	size(void) const
		{
			return (this->_arrSize);
		}
		// EXCEPTION CLASS
		class InvalidIndexException : public std::exception
		{
			public :

				const char* what() const throw()
				{
					return ("Error: invalid index");
				}
		};

	private:
	
		unsigned int	_arrSize;
		T				*_arrType;
};

#endif
