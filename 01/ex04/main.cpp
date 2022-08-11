/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:14 by cjulienn          #+#    #+#             */
/*   Updated: 2022/08/11 12:10:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/* ifstream is used to open a file within it to be able to manipulated it later 
*/

std::string	str_ops(std::string gnl, std::string s1, std::string s2)
{
	std::string		new_gnl(gnl);
	size_t			needle_pos;

	while (42)
	{
		needle_pos = new_gnl.find(s1);
		if (needle_pos == std::string::npos)
			break ;
		else
		{
			new_gnl.erase(needle_pos, s1.size());
			new_gnl.insert(needle_pos, s2);
		}
	}
	return (new_gnl);
}

int	file_ops(char **argv)
{
	std::ifstream		file;

	file.open(argv[1], std::ifstream::in);
	if (file.good() == false)
	{
		std::cout << "Error: The file does not exist and/or error with istream" << std::endl;
		return (1);
	}
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: The file is empty" << std::endl;
		file.close();
		return (1);
	}
	
	std::string			gnl;
	std::string			name_file(argv[1]);
	std::ofstream		new_file(name_file.append(".replace"));

	std::string			s1(argv[2]);
	std::string			s2(argv[3]);

	while (std::getline(file, gnl))
	{
		gnl = str_ops(gnl, s1, s2);
		new_file << gnl << std::endl;
	}
	file.close(); // close the original file
	new_file.close(); // close the newly created file
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	return (file_ops(argv));
}
