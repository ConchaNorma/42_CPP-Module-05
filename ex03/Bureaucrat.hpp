/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:07:03 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/29 17:58:29 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <iostream>

class Form;
class Bureaucrat
{
public:

	Bureaucrat();
	Bureaucrat(std::string name, int grade);

	const Bureaucrat& operator  =  (const Bureaucrat &other);
	Bureaucrat(const Bureaucrat &other);

	Bureaucrat& operator ++ ();
	Bureaucrat operator ++ (int);
	Bureaucrat& operator -- ();
	Bureaucrat operator -- (int);

	std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	void executeForm(Form const &form);

	class GradeTooHighException : public std::exception
	{
		virtual const char * what() const throw ();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char * what() const throw ();
	};

	void signForm(Form &form);

	~Bureaucrat();

private:
	const std::string _name;
	int	_grade;
};

std::ostream& operator << (std::ostream &out, const Bureaucrat &a);

#endif
