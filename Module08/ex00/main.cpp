/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:39:18 by khaimer           #+#    #+#             */
/*   Updated: 2024/03/23 00:50:43 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>


template <typename T>
int    easyfind(T *name, int number)
{   
        for (size_t i = 0; i < 4; i++)
        {
            if (number == name[i])
                return name[i];
        }   
        return -1;
}


int main()
{
    char khalil[4] = {'0', '3', 'F', '9'};
    char number = 'F';

    int result = easyfind(khalil, number);
    std::cout << (char)result << std::endl;
    
    return 0;
}