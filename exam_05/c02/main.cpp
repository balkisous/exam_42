/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:11:01 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 16:17:52 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Polymorph.hpp"
#include "SpellBook.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"

int main()
{
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");
	BrickWall model1;

	Polymorph* polymorph = new Polymorph();
	TargetGenerator tarGen;

	tarGen.learnTargetType(&model1);
	richard.learnSpell(polymorph);

	Fireball* fireball = new Fireball();

	richard.learnSpell(fireball);

	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
  return (0);
}