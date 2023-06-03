/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:26:25 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:20:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"


Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
	return ;
}

Dummy::~Dummy(void)
{
	return ;
}

ATarget	*Dummy::clone(void) const
{
	return (new Dummy());
}
