#ifndef ASPELL_H
# define ASPELL_H

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell(void);
		ASpell(std::string const &name, std::string const &effects);
		ASpell(ASpell const &src);
		ASpell &operator=(ASpell const &src);
		virtual ~ASpell(void);

		std::string const &getName(void) const;
		std::string const &getEffects(void) const;

		virtual ASpell *clone(void) const = 0;
		void			launch(ATarget const &ref) const;
};

#endif
