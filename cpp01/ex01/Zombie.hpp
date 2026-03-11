/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:30 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/25 23:28:08 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
private:
	std::string	name;

public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif