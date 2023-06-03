/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:29:17 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 11:58:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall")
{
	return ;
}

BrickWall::~BrickWall(void)
{
	return ;
}

ATarget	*BrickWall::clone(void) const
{
	return (new BrickWall());
}
