#include "ATarget.hpp"

ATarget::ATarget(void) { return ;}

ATarget::ATarget(std::string const &type) : _type(type)
{
	return ;
}

ATarget::ATarget(ATarget const &src)
{
	this->_type = src._type;
	return ;
}

ATarget &ATarget::operator=(ATarget const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

ATarget::~ATarget(void) { return ;}

std::string const &ATarget::getType(void) const {return (this->_type);}

void	ATarget::getHitBySpell(ASpell const &spell_ref) const
{
	std::cout << _type << " has been " << spell_ref.getEffects() << "!" << std::endl;
	return ;
}
