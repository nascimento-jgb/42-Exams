/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:55:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 09:32:56 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_H
# define ASPELL_H

#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	name;
		std::string	effects;

	public:
		ASpell(void);
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &src);
		ASpell &operator=(ASpell const *src);
		virtual ~ASpell(void);

		std::string	const getName(void) const;
		std::string const getEffects(void) const;

		virtual ASpell	*clone(void) const = 0;

		void	launch(ATarget const &target) const;
};

#endif

