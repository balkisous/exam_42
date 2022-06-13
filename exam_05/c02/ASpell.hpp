/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:10:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/10 11:00:11 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ASPELL_HPP
# define ASPELL_HPP

#include "Warlock.hpp"
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
	//constructor
	ASpell(std::string Name, std::string Effects);
	ASpell(void);							// constructor par defaut
	ASpell(ASpell const & rhs);				// constructor de recopie

	//fonction
	ASpell				&operator=(const ASpell & rhs) const;	//operator de recopie
	virtual ASpell		*clone(void) const = 0;
	std::string	const & getName(void) const;
	std::string	const & getEffects(void) const;
	void				launch_function(const ATarget &tar) const;

	//destructor
	~ASpell(void);				// destructor

	

	private:

	std::string	name;
	std::string	effects;
};

# endif
