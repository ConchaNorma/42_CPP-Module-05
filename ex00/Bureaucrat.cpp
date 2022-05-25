/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/25 08:05:10 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("???")
{
	std::cout << "DEFAULF contraction called" << std::endl;
	// this->name = "X";
	this->_grade = MIN_GRADE;
}
Bureaucrat::Bureaucrat(const std::string name , int grade) : _name(name), _grade(grade)
{
	std::cout << "NAMED contraction called" << std::endl;
	// this->_name = name;
	// this->_grade = grade;
}

const Bureaucrat& Bureaucrat::operator=  (const Bureaucrat &other)
{
	std::cout << "BUREAUCRAT Copy assignment operator called" << std::endl;
	if (this != &other){
		// *this = other;
		this->_name = other.getName();
		this->_grade = other.getGrade();
		// _name = other._name;
		// _grade = other._grade;
	}
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

	// std::string GradeTooHighException ();
	// std::string GradeTooLowException ();



Bureaucrat::~Bureaucrat()
{
	std::cout << "DEFAULF destraction called" << std::endl;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &a)
{

	out << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return out;
}
