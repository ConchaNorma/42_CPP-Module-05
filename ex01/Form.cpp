/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:36:52 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/25 22:13:47 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : f_name("???"), f_signed(false), f_gradeSign(1), f_gradeExecute(1)
{
	std::cout << "FORM DEFAULF contraction called" << std::endl;
}
Form::Form(const std::string name , int gradeSing, int gradeExecute) \
	: f_name(name), f_signed(false), f_gradeSign(gradeSing), f_gradeExecute(gradeExecute)
{
	std::cout << "FORM NAMED contraction called" << std::endl;
	if (f_gradeSign > MIN_GRADE)
		throw Form::GradeTooLowException();
	if (f_grade < MAX_GRADE)
		throw Form::GradeTooHighException();
}

const Form& Form::operator=  (const Form &other)
{
	std::cout << "FORM Copy assignment operator called" << std::endl;
	if (this != &other)
		this->f_signed = other.getSigned();
	return *this;
}

Form::Form(const Form &other)
{
	std::cout << "FORM Copy constructor called" << std::endl;
	*this = other;
}

std::string Form::getFormName() const {return f_name;}
int Form::getGradeSign() const {return f_gradeSign;}
int Form::getGradeExecute() const {return f_gradeExecute;}
int Form::isSigned() const {return f_signed;}

Form& Form::operator++()
{
	std::cout << "operator ++" << std::endl;
	this->_grade--;
	return *this;
}

Form Form::operator ++ (int)
{
	Form temp(*this);

	this->_grade--;
	return temp;
}

Form& Form::operator -- ()
{
	this->_grade++;
	return *this;
}

Form Form::operator -- (int)
{
	Form temp(*this);

	this->_grade++;
	return temp;
}

void Form::beSigned(const Bureaucrat &other) const
{
	if (other.getGrade() > this->f_gradeSign)
		throw Form::GradeTooLowException();
	this->f_signed = true;
}

void Form::decreaseGrade()
{
	if (_grade >= MIN_GRADE)
		throw Form::GradeTooLowException();
	this->_grade++;
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return "Form Grade is too High";
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return "Form Grade is too Low";
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
