/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 22:12:15 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern randomIntern;
	Form *resForm;

	resForm = randomIntern.makeForm("shrubbery creation", "target1");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("robotomy request", "target2");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("presidential pardon", "target3");
	std::cout << *resForm << std::endl;
	delete resForm;
	resForm = randomIntern.makeForm("error", "target4");

	return 0;
}
