/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/21 18:39:11 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Example
{
public:

	Example(int num);
	~Example();
	int		ToInt(void);

private:

	int					_example;
	static const int	_ex_lab = 8;
};
