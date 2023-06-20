#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>
#include <map>
#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

		Warlock(void);
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &src);

		SpellBook book;

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const &getName(void) const;
		std::string const &getTitle(void) const;
		void	setTitle(std::string const &title_ref);

		void	introduce(void) const;
		void	learnSpell(ASpell *spell_ptr);
		void	forgetSpell(std::string spell_name);
		void	launchSpell(std::string spell_name, ATarget const &target_ref);
};


#endif
