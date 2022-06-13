/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:27:36 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:23:13 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{
	return ;
}

Fireball	*Fireball::clone(void) const
{
	return new Fireball();
}

Fireball::~Fireball(void)
{
	return ;
}
