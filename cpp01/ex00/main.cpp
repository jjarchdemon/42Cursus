/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:42:06 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/23 16:23:42 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("Stack Zombie");

	Zombie *heapZombie = new Zombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	return(0);
}
