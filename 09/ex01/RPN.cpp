/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:49 by cjulienn          #+#    #+#             */
/*   Updated: 2023/04/01 13:10:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(char **rpn)
{	
	std::string			rpn_str = this->_joinStrParts(rpn);
	std::string			elem;
	std::stringstream	ss(rpn_str);
	int					type;

	if (rpn_str.empty())
		throw std::runtime_error("Error 1");
	while (!ss.eof())
	{
		std::getline(ss, elem, ' ');
		if (!elem.empty())
		{
			type = this->_identifyType(elem);
			if (type == INVAL)
				throw std::runtime_error("Error 2");
			if (type == NUMBER)
				this->_lifo.push(atoi(elem.c_str()));
			if (type == TOKEN)
			{
				if (this->_lifo.size() < 2)
					throw std::runtime_error("Error 3");
				this->_performOps(elem.front());
			}
		}
	}
	std::cout << this->_lifo.top() << std::endl; // printing result
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
int	RPN::_identifyType(std::string elem) // to test
{
	if (elem.size() == 1 && (elem.front() == '*' || elem.front() == '/'
	|| elem.front() == '+' || elem.front() == '-' ))
		return (TOKEN);
	if ((elem.size() == 1 && std::isdigit(elem.front())) || !elem.compare("10"))
		return (NUMBER);
	return (INVAL);
}

/*  */
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
			result = first / second;
			break;
		default:
			throw std::runtime_error("Error 4");
			break;
	}
	this->_lifo.push(result);
}

/* regroup the arguments into a std::string to form an entire RPN expression */
std::string	RPN::_joinStrParts(char **rpn)
{
	std::string		joined_args;
	std::size_t		spaces = 0;

	for (std::size_t i = 1; rpn && rpn[i]; i++)
	{
		joined_args += " ";
		joined_args += rpn[i];
	}
	/* checking if non empty RPN expression */
	for (std::size_t i = 0; i < joined_args.size(); i++)
	{
		if (std::isspace(joined_args[i]))
			spaces++;
	}
	if (spaces == joined_args.size())
		throw std::runtime_error("Error 5");
	joined_args = this->_trimWhitespaces(joined_args);
	/* check if last arg of the expression is a token, otherwise triggers error */
	if (joined_args[joined_args.size() - 2] != ' ' 
	|| this->_identifyType(joined_args.substr(joined_args.size() - 1)) != TOKEN)
		std::cout << joined_args.substr(joined_args.size() - 1) << std::endl;
	return (joined_args);
}

/* trim whitespaces */
std::string	RPN::_trimWhitespaces(std::string str)
{
	std::string		trimmed_str = str;
	
	while (trimmed_str.size() > 0 && std::isspace(trimmed_str.front()))
		trimmed_str = trimmed_str.substr(1);
	while (trimmed_str.size() > 0 && std::isspace(trimmed_str.back()))
		trimmed_str = trimmed_str.substr(0, trimmed_str.size() - 1);
	return (trimmed_str);
}
