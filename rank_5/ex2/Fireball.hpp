#ifndef FIREBALL_H
# define FIREBALL_H

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball(void);
		~Fireball(void);

		ASpell *clone(void) const;
};

#endif
