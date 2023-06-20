#ifndef ATARGET_H
# define ATARGET_H

#include <iostream>
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
		ATarget &operator=(ATarget const &src);
		virtual ~ATarget(void);

		std::string const &getType(void) const;

		virtual ATarget *clone(void) const = 0;
		void	getHitBySpell(ASpell const &spell_ref) const;
};

#endif
