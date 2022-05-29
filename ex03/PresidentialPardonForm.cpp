/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 18:30:05 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5), target("DefaultTarget")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
	: Form("PresidentialPardonForm", 25, 5), target(_target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: Form(other), target(other.target)
{}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	this->f_signed = other.f_signed;
	this->target = other.getTarget();
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkBeforeExecute(executor);

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
