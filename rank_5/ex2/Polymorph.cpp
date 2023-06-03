/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:54:22 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:55:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter")
{
	return ;
}

Polymorph::~Polymorph(void)
{
	return ;
}

ASpell	*Polymorph::clone(void) const
{
	return (new Polymorph());
}
