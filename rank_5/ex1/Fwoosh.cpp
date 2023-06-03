/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:00:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/02 16:56:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "Fwooshed")
{
	return ;
}

Fwoosh::~Fwoosh(void)
{
	return ;
}

ASpell	*Fwoosh::clone(void) const
{
	return (new Fwoosh());
}
