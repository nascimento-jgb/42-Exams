/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 10:54:24 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:55:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_H
# define POLYMORPH_H

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph(void);
		~Polymorph(void);
		virtual ASpell	*clone(void) const;
};

#endif
