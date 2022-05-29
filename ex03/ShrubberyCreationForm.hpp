/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:07:03 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 18:37:43 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

#include <string>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();
	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
};

#endif
