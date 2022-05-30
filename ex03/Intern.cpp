/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 22:13:18 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Form* Intern::shrub(std::string &target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::robot(std::string &target)
{
	return new RobotomyRequestForm(target);
}
Form* Intern::pardon(std::string &target)
{
	return new PresidentialPardonForm(target);
}

Form* Intern::error(std::string &target)
{
	std::cerr << "There is no specified form with passed name for the target '"<< target << "'." << std::endl;
	return NULL;
}

Form* Intern::makeForm(std::string form, std::string target)
{
	std::string array[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int end = sizeof(array) / sizeof(array[0]);

	Form* (Intern::*func[])(std::string&) = {
		&Intern::shrub,
		&Intern::robot,
		&Intern::pardon,
		&Intern::error
	};

	int i = 0;
	while (i < end && form != array[i])
		i++;

	return (this->*func[i])(target);
}
