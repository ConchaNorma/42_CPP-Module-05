/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 20:07:15 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), target("DefaultTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
	: Form("ShrubberyCreationForm", 145, 137), target(_target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: Form(other), target(other.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	this->f_signed = other.f_signed;
	this->target = other.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->checkBeforeExecute(executor);

	std::ofstream out;
	out.open(target + "_shrubbery");

	if (!out)
		return ;

	out <<
		"          &&& &&  & &				  ,@@@@@@@,\n"
		"      && &\\/&\\|& ()|/ @, &&		 ,@@@@@@@/@@,\n"
		"      &\\/(/&/&||/& /_/)_&/_&		,@@@@@/@@@@@@,\n"
		"   &() &\\/&|()|/&\\/ '%\" & ()   ,@@@@@\\@@@@/@@@\n"
		"  &_\\_&&_\\ |& |&&/&__%_/_& &&	@@\\@@/@@@/@@@/@@\n"
		"&&   && & &| &| /& & % ()& /&&		 @\\@@/@@@/@@@/@@\n"
		" ()&_---()&\\&\\|&&-&&--%---()~		@\\@@/@@@/\n"
		"     &&     \\|||						   |  |\n"
		"             |||						   |  |\n"
		"             |||						   |  |\n"
		"             |||						   |  |\n"
		"       , -=-~  .-^- _\\				\\/ ._\\//n"
		<< std::endl;

	out.close();
}
