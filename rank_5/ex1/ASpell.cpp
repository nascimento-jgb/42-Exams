/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:55:18 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 09:32:57 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(void)
{
	return	;
}

ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects)
{
	return ;
}

ASpell::ASpell(ASpell const &src)
{
	name = src.name;
	effects = src.effects;
	return ;
}

ASpell	&ASpell::operator=(ASpell const *src)
{
	this->name = src->name;
	this->effects = src->effects;
	return (*this);
}

ASpell::~ASpell(void)
{
	return ;
}

std::string	const ASpell::getName(void) const
{
	return (this->name);
}

std::string	const ASpell::getEffects(void) const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}

