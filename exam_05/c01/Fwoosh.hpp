/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:13:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 11:55:41 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class ASepll;

class Fwoosh : public ASpell
{
	public:
		Fwoosh(void);
		Fwoosh	*clone(void)const;
		
		virtual ~Fwoosh(void);
	
	private:
	
};

# endif