/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:02:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/01 21:13:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

class Intern
{

	public:

		Intern(void);
		Intern();
		~Intern();
		Intern(const Intern& original);
		
		Intern&		operator=(const Intern& original);
	
		
};



#endif