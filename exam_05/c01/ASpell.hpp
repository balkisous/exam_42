/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:10:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/10 11:19:47 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>

class ASpell
{
	public:
	//constructor
	ASpell(std::string Name, std::string Title);

	//fonction
	void		introduce() const;
	std::string	const & getName(void) const;
	std::string	const & getEffects(void) const;
	void		setTitle(std::string const &Title);

	//destructor
	virtual ~ASpell(void) = 0;				// destructor

	
	private:
	ASpell(void);				// constructor par defaut
	ASpell(ASpell const & rhs);		// constructor de recopie
	ASpell	&operator=(const ASpell & rhs);	//operator de recopie

	std::string	name;
	std::string	effects;
};

# endif
