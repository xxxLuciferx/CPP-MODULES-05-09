/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:31:48 by khaimer           #+#    #+#             */
/*   Updated: 2024/01/21 15:12:02 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyCreationForm(std::string const &target){
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardonForm(std::string const &target){
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomyRequestForm(std::string const &target){
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(const std::string& formName,const std::string& target)
{
	AForm* form[3] = {
		createShrubberyCreationForm(target),
		createPresidentialPardonForm(target),
		createRobotomyRequestForm(target)
	};
	std::string formNames[3] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};
	for (int i = 0; i < 3; i++){
		if (formNames[i] == formName){
			std::cout << "Intern creates " << formName << std::endl;
			return (form[i]);
		}
	}
    std::cout << "Intern can't create " << formName << std::endl;
	return (NULL);
}
