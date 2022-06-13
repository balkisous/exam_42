/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:13:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:23:32 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class ASepll;

class Fireball : public ASpell
{
	public:
		Fireball(void);
		Fireball	*clone(void)const;
		
		virtual ~Fireball(void);
	
	private:
	
};

# endif