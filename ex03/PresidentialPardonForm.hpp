/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:07:03 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 18:37:59 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

#include <string>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
};

#endif
