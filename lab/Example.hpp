/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:33:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 13:18:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Example
{
public:

	Example(const int num);
	~Example();
	int	getInt(void);
	int					_num;

private:

	static const int	_ex_lab = 8;
};
