/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:36:59 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/27 22:05:17 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
public:

	Form();
	Form(std::string name, int gradeSing, int gradeExecute);

	const Form& operator  =  (const Form &other);
	Form(const Form &other);

	std::string getFormName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &other);

	class GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw ();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw ();
	};

	class FormAlreadySigned : public std::exception
	{
		virtual const char * what() const throw ();
	};

	~Form();

private:
	const std::string	f_name;
	bool				f_signed;
	const int			f_gradeSign;
	const int			f_gradeExecute;
};

std::ostream& operator << (std::ostream &out, const Form &a);

#endif
