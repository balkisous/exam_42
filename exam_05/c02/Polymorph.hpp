/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:13:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:24:24 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class ASepll;

class Polymorph : public ASpell
{
	public:
		Polymorph(void);
		Polymorph	*clone(void)const;
		
		virtual ~Polymorph(void);
	
	private:
	
};

# endif