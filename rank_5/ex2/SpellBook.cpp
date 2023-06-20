#include "SpellBook.hpp"

SpellBook::SpellBook(void) {return ;}

SpellBook::~SpellBook(void)
{
	std::map<std::string, ASpell *>::iterator it_begin = this->magic.begin();
	std::map<std::string, ASpell *>::iterator it_end = this->magic.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->magic.clear();
	return ;
}

void	SpellBook::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		magic.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
	return ;
}

void	SpellBook::forgetSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = magic.find(spell_name);
	if (it != magic.end())
		delete it->second;
	magic.erase(spell_name);
	return ;
}

ASpell *SpellBook::createSpell(std::string const &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = magic.find(spell_name);
	if (it != magic.end())
		return magic[spell_name];
	return NULL;
}
