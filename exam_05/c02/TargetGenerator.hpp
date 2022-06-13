/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:39:52 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/13 16:22:18 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <iostream>
#include <vector>

class TargetGenerator
{
	public:
	TargetGenerator(void);

	~TargetGenerator(void);

	void	learnTargetType(ATarget *atar);
	void	forgetTargetType(std::string const &target);
	ATarget	*createTarget(std::string const &type);

	private:
	TargetGenerator(TargetGenerator const & rhs);
	TargetGenerator &operator= (TargetGenerator const & rhs);
	std::vector<ATarget *> target_list;
};

# endif