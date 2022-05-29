/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 18:38:26 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), target("DefaultTarget")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
	: Form("RobotomyRequestForm", 72, 45), target(_target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: Form(other), target(other.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	this->f_signed = other.f_signed;
	this->target = other.getTarget();
	return *this;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkBeforeExecute(executor);

	std::cout << "... drilling noises ..." << std::endl;
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}
