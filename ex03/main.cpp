/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 20:12:27 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void changeGrade(Bureaucrat &obj, int newGrade)
{
	if (newGrade < MAX_GRADE || newGrade > MIN_GRADE)
		return ;
	while (obj.getGrade() > newGrade) { obj.increaseGrade(); }
	std::cout	<< "--> Bureaucrat grade has been increased to "
				<< newGrade << "." << std::endl;
}

int main()
{
	Bureaucrat a("Elik", 150);
	Form *forms[] = {
		new ShrubberyCreationForm("Target1"),
		new RobotomyRequestForm("Target2"),
		new PresidentialPardonForm("Target3")
	};

	for (int i = 0; i < 3; i++)
	{
		a.executeForm(*forms[i]);
		a.signForm(*forms[i]);
		changeGrade(a, forms[i]->getGradeSign());
		a.signForm(*forms[i]);
		a.signForm(*forms[i]);
		a.executeForm(*forms[i]);
		changeGrade(a, forms[i]->getGradeExecute());
		a.executeForm(*forms[i]);
	}

	std::cout << a << std::endl;

	for (int i = 0; i < 3; i++)
		delete forms[i];
	return 0;
}
