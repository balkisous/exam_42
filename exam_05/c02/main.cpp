/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:11:01 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 14:11:29 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

int main()
{
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();

	std::cout << "----1----" << std::endl;

	richard.learnSpell(fwoosh);

	std::cout << "----2----" << std::endl;
	richard.introduce();
	richard.launchSpell("Fwoosh", bob);


	std::cout << "----3----" << std::endl;
	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);
}