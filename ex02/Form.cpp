/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:36:52 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/27 00:16:30 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : f_name("???"), f_signed(false), f_gradeSign(1), f_gradeExecute(1)
{
	std::cout << "FORM DEFAULF contraction called" << std::endl;
}
Form::Form(std::string name , int gradeSing, int gradeExecute) \
	: f_name(name), f_signed(false), f_gradeSign(gradeSing), f_gradeExecute(gradeExecute)
{
	std::cout << "FORM NAMED contraction called" << std::endl;
	if (f_gradeSign > MIN_GRADE || f_gradeExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
	if (f_gradeSign < MAX_GRADE || f_gradeExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
}

const Form& Form::operator=  (const Form &other)
{
	std::cout << "FORM Copy assignment operator called" << std::endl;
	if (this != &other)
		this->f_signed = other.isSigned();
	return *this;
}

Form::Form(const Form &other) : f_name(other.f_name),
								f_signed(other.f_signed),
								f_gradeSign(other.f_gradeSign),
								f_gradeExecute(other.f_gradeExecute)
{
	std::cout << "FORM Copy constructor called" << std::endl;
}

std::string Form::getFormName() const {return f_name;}
int Form::getGradeSign() const {return f_gradeSign;}
int Form::getGradeExecute() const {return f_gradeExecute;}
bool Form::isSigned() const {return f_signed;}

void Form::beSigned(const Bureaucrat &other)
{
	if (this->f_signed == true)
		throw Form::FormAlreadySigned();
	if (other.getGrade() > this->f_gradeSign || other.getGrade() > this->f_gradeExecute)
		throw Form::GradeTooLowException();
	this->f_signed = true;
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return "Form Grade is too High";
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return "Form Grade is too Low";
}

const char *Form::FormAlreadySigned::what() const throw ()
{
	return "Form is Already Signed";
}

Form::~Form()
{
	std::cout << "DEFAULF destraction called" << std::endl;
}

std::ostream& operator << (std::ostream &out, const Form &a)
{

	out << "FORM name " <<a.getFormName() << "; sign status = " << a.isSigned() \
		<< "; Grade to Sign is " << a.getGradeSign() << "; Grade to Execute is " << a.getGradeExecute() << std::endl;
	return out;
}
