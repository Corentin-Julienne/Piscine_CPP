/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:49 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/05 09:23:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(char **rpn)
{	
	std::string			rpn_str = rpn[1];
	std::string			elem;
	std::stringstream	ss(rpn_str);
	int					type;

	if (rpn_str.empty())
		throw std::runtime_error("Error");
	while (!ss.eof())
	{
		std::getline(ss, elem, ' ');
		if (!elem.empty())
		{
			type = this->_identifyType(elem);
			if (type == INVAL)
				throw std::runtime_error("Error");
			if (type == NUMBER)
				this->_lifo.push(atoi(elem.c_str()));
			if (type == TOKEN)
			{
				if (this->_lifo.size() < 2)
					throw std::runtime_error("Error");
				this->_performOps(elem.front());
			}
		}
	}
	std::cout << this->_lifo.top() << std::endl;
}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _lifo(other._lifo) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_lifo = other._lifo;
	return *this;
}

/* check whether the input provided is a number, or an accepted, or neither of those */
int	RPN::_identifyType(std::string elem)
{
	if (elem.size() == 1 && (elem.front() == '*' || elem.front() == '/'
	|| elem.front() == '+' || elem.front() == '-' ))
		return (TOKEN);
	if ((elem.size() == 1 && std::isdigit(elem.front())) || !elem.compare("10"))
		return (NUMBER);
	return (INVAL);
}

/* perform all ops, trigger exception if division per 0 */
void	RPN::_performOps(char token)
{
	int			first;
	int			second;
	int			result;

	second = this->_lifo.top();
	this->_lifo.pop();
	first = this->_lifo.top();
	this->_lifo.pop();

	switch (token)
	{
		case '+':
			result = first + second;
			break;
		case '-':
			result = first - second;
			break;
		case '*':
			result = first * second;
			break;
		case '/':
			if (second == 0)
				throw std::runtime_error("Error");
			result = first / second;
			break;
		default:
			throw std::runtime_error("Error");
			break;
	}
	this->_lifo.push(result);
}
