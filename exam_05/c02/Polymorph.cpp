/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:27:36 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:25:11 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turn into a critter")
{
	return ;
}

Polymorph	*Polymorph::clone(void) const
{
	return new Polymorph();
}

Polymorph::~Polymorph(void)
{
	return ;
}
