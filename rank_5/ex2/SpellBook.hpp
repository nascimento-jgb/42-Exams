#ifndef SPELLBOOK_H
# define SPELLBOOK_H

#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(SpellBook const &src);
		SpellBook &operator=(SpellBook const &src);

		std::map <std::string, ASpell*> magic;

	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell *spell_ptr);
		void	forgetSpell(std::string const &spell_name);
		ASpell *createSpell(std::string const &spell_name);
};
#endif
