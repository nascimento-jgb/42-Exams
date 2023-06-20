#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
	return ;
}

Warlock::~Warlock(void)
{
	std::map<std::string, ASpell *>::iterator it_begin = this->magic.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->magic.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->magic.clear();
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
	if (spell_ptr)
		magic.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
	return ;
}

void	Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator it = magic.find(spell_name);
	if (it != magic.end())
		delete it->second;
	magic.erase(spell_name);
	return ;
}

void	Warlock::launchSpell(std::string spell_name, ATarget const &target_ref)
{
	ASpell *spell = magic[spell_name];
	if (spell)
		spell->launch(target_ref);
	return ;
}
