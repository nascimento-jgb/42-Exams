/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:37:26 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/02 14:56:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget(void)
{
	return	;
}

ATarget::ATarget(std::string const &type) : _type(type)
{
	return ;
}

ATarget::ATarget(ATarget const &src)
{
	_type =src._type;
	return ;
}

ATarget	&ATarget::operator=(ATarget const *src)
{
	this->_type = src->_type;
	return (*this);
}

ATarget::~ATarget(void)
{
	return ;
}

std::string	const ATarget::getType(void) const
{
	return (this->_type);
}

void	ATarget::getHitBySpell(ASpell const &aspell) const
{
	std::cout << this->_type << " has been " << aspell.getEffects() << "!" <<std::endl;
	std::cout << this->_type << " is the ATarget's type, and " << aspell.getEffects() <<
		" is the return of the ASpell's getEffects function." << std::endl;
	return ;
}
