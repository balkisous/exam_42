/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:23:56 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 11:12:03 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string Type) :  type(Type)
{
	return ;
}


ATarget::~ATarget(void)
{
	return ;
}

std::string const &	ATarget::getType(void) const
{
	return (this->type);
}

void	ATarget::getHitBySpell(const ASpell &asp) const
{
	std::cout << this->type << " has been " << asp.getEffects() << "!" << std::endl;
}
