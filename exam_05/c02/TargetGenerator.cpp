/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:39:47 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 17:49:23 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "TargetGenerator.hpp" 

TargetGenerator::TargetGenerator(void)
{
	return ;
}

TargetGenerator::~TargetGenerator(void)
{
	std::vector<ATarget *>::iterator it = target_list.begin();
	std::vector<ATarget *>::iterator ite = target_list.end();

	while (it != ite)
	{
		delete (*it);
		it++;
	}
	return ;
}

void	TargetGenerator::learnTargetType(ATarget *atar)
{
	std::vector<ATarget *>::iterator it = target_list.begin();
	std::vector<ATarget *>::iterator ite = target_list.end();

	if (!atar)
		return ;
	while (it != ite)
	{
		if ((*it)->getType() == atar->getType())
			return ;
		it++;
	}
	target_list.push_back(atar->clone());
	return ;
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	std::vector<ATarget *>::iterator it = target_list.begin();
	std::vector<ATarget *>::iterator ite = target_list.end();

	while (it != ite)
	{
		if ((*it)->getType() == target)
		{
			delete (*it);
			target_list.erase(it);
			return ;
		}
		it++;
	}
	return ;
}

ATarget	*TargetGenerator::createTarget(std::string const &type)
{
	std::vector<ATarget *>::iterator it = target_list.begin();
	std::vector<ATarget *>::iterator ite = target_list.end();

	while (it != ite)
	{
		if ((*it)->getType() == type)
		{
			return (*it);
		}
		it++;
	}
	return NULL;
}