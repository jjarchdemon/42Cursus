/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:42:19 by jambatt           #+#    #+#             */
/*   Updated: 2026/05/05 19:23:22 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string m_name;

public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif