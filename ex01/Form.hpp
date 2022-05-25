/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:36:59 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/25 22:13:50 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# define GRADE_TO_SIGN 1
# define GRADE_TO_EXECUTE 150

# include <iostream>
# include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
public:

	Form();
	Form(std::string name, int grade);

	const Form& operator  =  (const Form &other);
	Form(const Form &other);

	Form& operator ++ ();
	Form operator ++ (int);
	Form& operator -- ();
	Form operator -- (int);

	std::string getFormName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &other) const;
	void decreaseGrade();

	class GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw ();
	};

	class GradeTooLowException : public std::exception
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
