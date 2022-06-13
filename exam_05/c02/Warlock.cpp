/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:23:56 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:09:14 by bben-yaa         ###   ########.fr       */
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
	std::cout << this->name << ": My job is done!" << std::endl;
	std::vector<ASpell*>::iterator it = spells.begin();
	std::vector<ASpell*>::iterator ite = spells.end();

	while (it != ite)
	{
		this->spells.erase(it);
		it++;
	}
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
	std::vector<ASpell *>::iterator it = spells.begin();
	std::vector<ASpell *>::iterator ite = spells.end();

	if (!asp)
		return ; 
	while (it != ite)
	{
		if ((*it)->getName() == asp->getName())
			return ;
		it++;
	}
	spells.push_back(asp->clone());
	return ;
}

void	Warlock::forgetSpell(std::string sp_name)	//oublie le spell
{
	std::vector<ASpell*>::iterator it = spells.begin();
	std::vector<ASpell*>::iterator ite = spells.end();

	while (it != ite)
	{
		if ((*it)->getName() == sp_name)
		{
			spells.erase(it);
			return ;
		}
		it++;
	}
	return ;
}
void	Warlock::launchSpell(std::string sp_name, ATarget &tar)
{
	std::vector<ASpell *>::iterator it = spells.begin();
	std::vector<ASpell *>::iterator ite = spells.end();

	while (it != ite)
	{
		if ((*it)->getName() == sp_name)
		{
			(*it)->launch_function(tar);
			return ;
		}
		it++;
	}
	return ;
}
