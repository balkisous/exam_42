/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:27:36 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:29:47 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall")
{
	return ;
}

BrickWall	*BrickWall::clone(void) const
{
	return new BrickWall();
}

BrickWall::~BrickWall(void)
{
	return ;
}
