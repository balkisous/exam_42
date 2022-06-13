/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:45:57 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 17:49:10 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
	//constructor
	ATarget(std::string Type);
	ATarget(void);							// constructor par defaut
	ATarget(ATarget const & rhs)				// constructor de recopie
	{
		*this = rhs;
	}
	//fonction
	ATarget		&operator=(const ATarget & rhs)	//operator de recopie
	{
		this->type = rhs.getType();
		return (*this);
	}
	std::string	const & getType(void) const ;
	void	getHitBySpell(const ASpell &asp) const ;
	virtual ATarget* clone() const = 0;
	

	//destructor
	virtual ~ATarget(void);				// destructor

	

	private:

	std::string	type;
};

# endif
