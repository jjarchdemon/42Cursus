/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:26:21 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/25 23:32:54 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];
	int i = 0;
	while (i< N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}