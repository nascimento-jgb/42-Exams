/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:27:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 09:28:29 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Dummy_H
# define Dummy_H

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy(void);
		~Dummy(void);
		virtual ATarget	*clone(void) const;
};

#endif
