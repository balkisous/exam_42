/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:23:56 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 11:10:27 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string Name, std::string Effects) : name(Name), effects(Effects)
{
	return ;
}

ASpell::~ASpell(void)
{
	return ;
}

void	ASpell::launch_function(const ATarget &tar) const
{
	tar.getHitBySpell(*this);
}

std::string const &	ASpell::getEffects(void) const
{
	return (this->effects);
}

std::string const &	ASpell::getName(void) const
{
	return (this->name);
}
