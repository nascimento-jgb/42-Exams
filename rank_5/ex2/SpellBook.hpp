/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:35:53 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 12:14:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include "ASpell.hpp"
#include <map>

class SpellBook
{

	private:
		SpellBook(SpellBook const &src);
		SpellBook &operator=(SpellBook const &src);

		std::map<std::string, ASpell *> arr_spells;

	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell *spell_ptr);
		void	forgetSpell(std::string const &spell_name);
		ASpell	*createSpell(std::string const &spell_name);
};

#endif
