/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/27 07:59:21 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("???")
{
	std::cout << "DEFAULF contraction called" << std::endl;
	this->_grade = MIN_GRADE;
}
Bureaucrat::Bureaucrat(const std::string name , int grade) : _name(name), _grade(grade)
{
	std::cout << "NAMED contraction called" << std::endl;
	if (_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

const Bureaucrat& Bureaucrat::operator=  (const Bureaucrat &other)
{
	std::cout << "BUREAUCRAT Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_grade = other.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "BUREAUCRAT Copy constructor called" << std::endl;
	*this = other;
}

std::string Bureaucrat::getName() const {return _name;}
int Bureaucrat::getGrade() const {return _grade;}

Bureaucrat& Bureaucrat::operator++()
{
	std::cout << "operator ++" << std::endl;
	this->_grade--;
	return *this;
}

Bureaucrat Bureaucrat::operator ++ (int)
{
	Bureaucrat temp(*this);

	this->_grade--;
	return temp;
}

Bureaucrat& Bureaucrat::operator -- ()
{
	this->_grade++;
	return *this;
}

Bureaucrat Bureaucrat::operator -- (int)
{
	Bureaucrat temp(*this);

	this->_grade++;
	return temp;
}

void Bureaucrat::increaseGrade()
{
	if (_grade <= MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade >= MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Grade is too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Grade is too Low";
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getFormName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "DEFAULF destraction called" << std::endl;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &a)
{

	out << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return out;
}
