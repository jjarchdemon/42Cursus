/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:58:25 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/26 13:05:48 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string greeting = "HI THIS IS BRAIN";
	std::string *stringPTR = &greeting;
	std::string &stringREF = greeting;

	std::cout << "The memory address of the string variable: " << &greeting << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << greeting << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}