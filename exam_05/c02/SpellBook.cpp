/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:43:38 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 15:28:45 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
	return ;
}

SpellBook::~SpellBook(void)
{
	std::vector<ASpell *>::iterator it = spells_book.begin();
	std::vector<ASpell *>::iterator ite = spells_book.end();

	while (it != ite)
	{
		delete (*it);
		it++;
	}
	return ;
}

void	SpellBook::learnSpell(ASpell *asp)
{
	std::vector<ASpell *>::iterator it = spells_book.begin();
	std::vector<ASpell *>::iterator ite = spells_book.end();

	while (it != ite)
	{
		if ((*it)->getName() == asp->getName())
			return ;
		it++;
	}
	spells_book.push_back(asp->clone());
}

void	SpellBook::forgetSpell(std::string const &sp_name)
{
	std::vector<ASpell *>::iterator it = spells_book.begin();
	std::vector<ASpell *>::iterator ite = spells_book.end();

	while (it != ite)
	{
		if ((*it)->getName() == sp_name)
		{
			delete (*it);
			spells_book.erase(it);
		}
		it++;
	}
}

ASpell	*SpellBook::createSpell(std::string const &sp_name)
{
	std::vector<ASpell *>::iterator it = spells_book.begin();
	std::vector<ASpell *>::iterator ite = spells_book.end();

	while (it != ite)
	{
		if ((*it)->getName() == sp_name)
		{
			return (*it);
		}
		it++;
	}
	return NULL;
}