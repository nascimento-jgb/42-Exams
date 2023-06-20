#include "ASpell.hpp"

ASpell::ASpell(void) { return ;}

ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects)
{
	return ;
}

ASpell::ASpell(ASpell const &src)
{
	this->name = src.name;
	this->effects = src.effects;
	return ;
}

ASpell &ASpell::operator=(ASpell const &src)
{
	if (this == &src)
		return (*this);
	this->name = src.name;
	this->effects = src.effects;
	return (*this);
}

ASpell::~ASpell(void) { return ;}

std::string const &ASpell::getName(void) const {return (this->name);}

std::string const &ASpell::getEffects(void) const { return (this->effects);}

void	ASpell::launch(ATarget const &ref) const
{
	ref.getHitBySpell((*this));
}
