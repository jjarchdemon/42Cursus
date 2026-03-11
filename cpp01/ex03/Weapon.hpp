/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:33:38 by jambatt           #+#    #+#             */
/*   Updated: 2026/01/30 12:47:41 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon();
	~Weapon();
	const std::string& getType();
	void setType(std::string type);

}


#endif