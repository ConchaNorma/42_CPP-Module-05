/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:26:42 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/23 08:09:21 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "DEFAULF contraction called" << std::endl;
	this->name = "";
	this->grade = MIN_GRADE;
}
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "NAMED contraction called" << std::endl;
	this->name = name;
	this->grade = grade;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &other)
{
	std::cout << "BUREAUCRAT Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.getName();
	this->grade = other.getGrade();

	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "BUREAUCRAT Copy constructor called" << std::endl;
	*this = other;
}

std::string const getName() const {return name;}
int getGrade() {return grade;}

Bureaucrat& Bureaucrat::operator ++ ()
{
	this->grade--;
	return *this;
}

Bureaucrat Bureaucrat::operator ++ (int)
{
	Bureaucrat temp(*this);

	this->grade--;
	return temp;
}

Bureaucrat& Bureaucrat::operator -- ()
{
	this->grade++;
	return *this;
}

Bureaucrat Bureaucrat::operator -- (int)
{
	Bureaucrat temp(*this);

	this->grade++;
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
