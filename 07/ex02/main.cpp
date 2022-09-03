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
    srand(time(NULL)); // WTF is that ?
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        // check if overloading operator = is functionnal
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != numbers[i])
            {
                std::cerr << "Check overloading operator = : didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        //  check if constructor by copy is functionnal
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i])
            {
                std::cerr << "Check copy operator : didn't save the same value!!" << std::endl;
                return 1;
            }
        }
    }

    for (int i = 0; i < MAX_VAL; i++) // should not be triggered
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) // should trigger exception
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) // should trigger exception
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL - 1];
        std::cout << "numbers[MAX_VAL - 1]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < MAX_VAL; i++) 
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    // system("leaks Array"); // debug tool, kill after use
    return 0;
}
