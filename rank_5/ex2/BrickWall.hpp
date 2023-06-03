/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:29:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 11:30:14 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_H
# define BRICKWALL_H

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall(void);
		~BrickWall(void);
		virtual ATarget	*clone(void) const;
};

#endif
