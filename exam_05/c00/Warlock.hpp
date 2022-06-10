/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:10:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/10 11:00:11 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

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
	~Warlock(void);				// destructor

	

	private:
	Warlock(void);				// constructor par defaut
	Warlock(Warlock const & rhs);		// constructor de recopie
	Warlock	&operator=(const Warlock & rhs);	//operator de recopie

	std::string	name;
	std::string	title;
};

# endif
