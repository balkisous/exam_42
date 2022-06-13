/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:23:56 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 17:51:30 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string Name, std::string Title) : name(Name), title(Title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

void	Warlock::introduce() const
{
	
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	return ;
}

std::string const &	Warlock::getTitle(void) const
{
	return (this->title);
}

std::string const &	Warlock::getName(void) const
{
	return (this->name);
}

void	Warlock::setTitle(std::string const & Title)
{
	this->title = Title;
}

void	Warlock::learnSpell(ASpell *asp)	//apprend le spell
{
	spell.learnSpell(asp);
	return ;
}

void	Warlock::forgetSpell(std::string sp_name)	//oublie le spell
{
	spell.forgetSpell(sp_name);
	return ;
}
void	Warlock::launchSpell(std::string sp_name, ATarget &tar)
{
	ASpell *tmp = spell.createSpell(sp_name);
	if (tmp)
		tmp->launch_function(tar);
	return ;
}
