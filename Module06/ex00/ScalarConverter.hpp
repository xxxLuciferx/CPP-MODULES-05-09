/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:28:11 by khaimer           #+#    #+#             */
/*   Updated: 2024/01/27 10:04:30 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    public :
        ScalarConverter(const ScalarConverter& value);
        static void convert(const std::string& value);

        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter& ref);
    private:
        ScalarConverter();
};