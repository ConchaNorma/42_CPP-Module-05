/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <cnorma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 07:58:57 by cnorma            #+#    #+#             */
/*   Updated: 2022/05/25 21:19:31 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "--- Test01 (grade 1, decrease by 1) -->" << std::endl;
	try{
		Bureaucrat b("TEST_01", 1);
		std::cout << "Before: " << b << std::endl;
		b.decreaseGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test02 (grade 1, increase by 1) -->" << std::endl;
	try{
		Bureaucrat b("TEST_02", 1);
		std::cout << "Before: " << b << std::endl;
		b.increaseGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test03 (grade 150, increase by 1) -->" << std::endl;
	try{
		Bureaucrat b("TEST_03", 150);
		std::cout << "Before: " << b << std::endl;
		b.increaseGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test04 (grade 150, decrease by 1) -->" << std::endl;
	try{
		Bureaucrat b("TEST_04", 150);
		std::cout << "Before: " << b << std::endl;
		b.decreaseGrade();
		std::cout << "After: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test05 (create obj. with grade <1) -->" << std::endl;
	try{
		Bureaucrat b("TEST_05", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Test06 (create obj. with grade >150) -->" << std::endl;
	try{
		Bureaucrat b("TEST_06", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
