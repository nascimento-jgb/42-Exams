/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:52:44 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:55:24 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_H
# define FIREBALL_H

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball(void);
		~Fireball(void);
		virtual ASpell	*clone(void) const;
};

#endif
