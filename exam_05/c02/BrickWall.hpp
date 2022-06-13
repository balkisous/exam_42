/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:27:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:29:37 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget
{
	public:
		BrickWall(void);
		BrickWall	*clone(void)const;
		
		virtual ~BrickWall(void);
	
	private:
	
};

# endif