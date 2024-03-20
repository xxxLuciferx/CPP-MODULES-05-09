/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:33:22 by khaimer           #+#    #+#             */
/*   Updated: 2024/03/20 23:52:27 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


template <typename arr>
void    iter(arr *array, size_t length, void (*func)(arr&))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename arr>
void    print(arr &array)
{
    std::cout << "Print Called |" << array << std::endl;
}



int main() 
{
    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    iter( tab, 5, print );
    iter( tab2, 5, print );
    // iter( tab, 5, print<const int> );
    iter( tab2, 5, print<Awesome> );
    return 0;
}

// int main()
// {
// 	char array[] = "ABCD";
// 	// int array[] = {1, 2, 3, 4};
// 	// size_t lenght = sizeof(array) / sizeof(array[0]);
// 	size_t lenght = 4;

// 	std::cout << "original array:" << std::endl;
// 	// for (size_t i = 0 ; i < lenght; i++)
// 	// 	std::cout << array[i] << std::endl;
	
// 	// iter(array, lenght, print);
    
// 	iter(array, lenght, print);
// 	std::cout << "after iter function :" << std::endl;
	
// 	for (size_t i = 0 ; i < lenght; i++)
// 		std::cout << array[i] << std::endl;
// 	return (0);
// }