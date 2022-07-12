/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:14 by cjulienn          #+#    #+#             */
/*   Updated: 2022/07/05 17:54:03 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	testing_procedure()
{
	// TO IMPLEMENT
}

int main(int argc, char **argv)
{
	std::string 		name_new_file(argv[1]);
	// std::string			s1(argv[2]);
	// std::string			s2(argv[3]);
	std::string			gnl;
	std::ofstream		new_file(name_new_file.append(".replace"));
	std::ifstream		file(argv[1]);

	if (argc != 4)
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
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
	while (42) 
	{
		// std::size_t		index;
		
		std::getline(file, gnl, '\n');
		std::cout << gnl << std::endl; // test
		break ;
		if (gnl.empty())
			break ;
		new_file << gnl << std::endl;
	}
	file.close(); // close file, then return
	new_file.close();
	return (0);
}
