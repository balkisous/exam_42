/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:23:56 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/10 11:01:26 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string Name, std::string Title) : name(Name), title(Title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->name << ": My job is done!" << std::endl;
}

std::string const &	Warlock::getTitle(void) const
{
	return (this->title);
}

std::string const &	Warlock::getName(void) const
{
	return (this->name);
}

void	Warlock::setTitle(std::string const & Title)
{
	this->title = Title;
}
