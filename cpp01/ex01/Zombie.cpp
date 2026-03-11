/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:25 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/26 12:55:10 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
	std::cout << "Alive!!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
