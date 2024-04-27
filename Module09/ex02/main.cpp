/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:34:31 by khaimer           #+#    #+#             */
/*   Updated: 2024/04/27 17:36:15 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    
    PmergeMe khalil;
    // std::vector<int> vec;
    if (ac > 1)
    {
        try
        {
            khalil.parsing(ac, av);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cerr << "bad input \n";
        return 1;
    }
    return 0;
}