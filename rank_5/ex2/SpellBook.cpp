/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:42:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 12:19:40 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
	return ;
}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell *>::iterator ini = this->arr_spells.begin();
	while (ini != this->arr_spells.end())
	{
		delete ini->second;
		++ini;
	}
	this->arr_spells.clear();
}

void	SpellBook::learnSpell(ASpell *aspell_ptr)
{
	if (aspell_ptr)
		arr_spells.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void	SpellBook::forgetSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator search = arr_spells.find(spell_name);
	if (search != arr_spells.end())
		delete search->second;
	arr_spells.erase(spell_name);
}

ASpell	*SpellBook::createSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator search = arr_spells.find(spell_name);
	if (search != arr_spells.end())
		return arr_spells[spell_name];
	return NULL;
}
