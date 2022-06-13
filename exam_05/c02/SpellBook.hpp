/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:33:01 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 15:29:05 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ATarget.hpp"


class ASpell;

class SpellBook 
{
	public:

	SpellBook(void);
	virtual ~SpellBook(void);

	void	learnSpell(ASpell *asp);
	void	forgetSpell(std::string const &sp_name);
	ASpell	*createSpell(std::string const &sp_name);

	private:
	SpellBook(SpellBook const &rhs);
	SpellBook &operator=(SpellBook const &rhs);
	std::vector<ASpell*> spells_book;
};

# endif