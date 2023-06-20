#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
	return ;
}

Warlock::~Warlock(void)
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
	return ;
}

std::string const &Warlock::getName(void) const
{
	return (this->_name);
}

std::string const &Warlock::getTitle(void) const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const &title_ref)
{
	this->_title = title_ref;
	return ;
}

void	Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell_ptr)
{
	book.learnSpell(spell_ptr);
}

void	Warlock::forgetSpell(std::string spell_name)
{
	book.forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget const &target_ref)
{
	ASpell *spell = book.createSpell(spell_name);
	if (spell)
		spell->launch(target_ref);
	return ;
}
