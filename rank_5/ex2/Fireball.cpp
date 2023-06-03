/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:53:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:53:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{
	return ;
}

Fireball::~Fireball(void)
{
	return ;
}

ASpell	*Fireball::clone(void) const
{
	return (new Fireball());
}
