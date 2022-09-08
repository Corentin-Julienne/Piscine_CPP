/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:28:45 by cjulienn          #+#    #+#             */
/*   Updated: 2022/09/03 12:52:30 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Array numbers have a size of " << numbers.size() << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        // check if overloading operator = is functionnal
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != numbers[i])
            {
                std::cerr << "Problem with overloading operator =" << std::endl;
                return 1;
            }
        }
        //  check if constructor by copy is functionnal
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "Prblem with copy constructor" << std::endl;
                return 1;
            }
        }
    }

    for (int i = 0; i < MAX_VAL; i++) // should not be triggered
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "mirror value is different from number value" << std::endl;
            return 1;
        }
    }
    
    std::cout << "trying to access to some indexes" << std::endl;
    try
    {
        std::cout << numbers[-2] << std::endl;
    }
    catch(const std::exception& e) // should trigger exception
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << numbers[MAX_VAL] << std::endl;
    }
    catch(const std::exception& e) // should trigger exception
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << numbers[MAX_VAL - 1] << " for temlate Array and " << mirror[MAX_VAL - 1] << " for the mirror array" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "trying with an Array of type std::string" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    Array<std::string> strs(2);

    std::cout << "Array of strings have a size of " << strs.size() << std::endl;
    try
    {
        strs[0] = "Index 0 exists";
        std::cout << strs[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try
    {
        strs[1] = "Index 1 exists";
        std::cout << strs[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    try
    {
        strs[2] = "Index 2 does not exist !!!";
        std::cout << strs[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    // delete in order to avoid leaks

    delete [] mirror;//
    //system("leaks Array"); // debug tool, kill after use
    return 0;
}
