/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:51 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/03 12:10:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

#define NUMBER		0
#define TOKEN		1
#define INVAL		2

class RPN
{
	public:

		RPN(char **rpn);
		~RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

		const std::stack<std::string>	getStack(void) const;

	private:

		bool	_isToken(std::string input);
		bool	_isNumber(std::string input);
		int		_identifyType(std::string input);
		void	_performOps(char token);

		std::stack<int>				_lifo;

		RPN(void); // don't use that !!!
};

#endif
