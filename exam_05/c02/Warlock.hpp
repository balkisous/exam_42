/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:10:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 15:05:15 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <iostream>
#include <vector>

class ATarget;
class ASpell;
class SpellBook;

class Warlock
{
	public:
	//constructor
	Warlock(std::string Name, std::string Title);

	//fonction
	void		introduce() const;
	std::string	const & getName(void) const;
	std::string	const & getTitle(void) const;
	void		setTitle(std::string const &Title);

	//destructor
	~Warlock(void);								// destructor

	void	learnSpell(ASpell *asp);
	void	forgetSpell(std::string sp_name);
	void	launchSpell(std::string sp_name, ATarget &tar);

	private:
	Warlock(void);								// constructor par defaut
	Warlock(Warlock const & rhs);				// constructor de recopie
	Warlock	&operator=(const Warlock & rhs);	//operator de recopie

	std::string	name;
	std::string	title;
	SpellBook	spell;
};

# endif
