/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:07:03 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 18:37:49 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

#include <string>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

	RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
};

#endif
