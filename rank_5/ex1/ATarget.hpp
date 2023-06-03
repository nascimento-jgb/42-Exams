/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:36:54 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/02 14:49:12 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_H
# define ATARGET_H

#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string	_type;
	public:
		ATarget(void);
		ATarget(std::string const &type);
		ATarget(ATarget const &src);
		ATarget &operator=(ATarget const *src);
		virtual ~ATarget(void);

		std::string	const getType(void) const;

		void getHitBySpell(ASpell const &aspell) const;

		virtual ATarget	*clone(void) const = 0;
};

#endif
