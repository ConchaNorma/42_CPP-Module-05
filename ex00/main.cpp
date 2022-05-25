/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/25 07:45:46 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b("Ivan", 2);

	std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;
	std::cout << b++ << std::endl;
	std::cout << b.getName() << " has grade " << b.getGrade() << std::endl;

	// std::cout << b++ << std::endl;

	try
	{
		if (b.getGrade() > MIN_GRADE)
			throw "Bureaucrat::GradeTooHighException";
		if (b.getGrade() < MAX_GRADE)
			throw "Bureaucrat::GradeTooLowException";
		std::cout << "OK" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
