#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void) {return ;}

TargetGenerator::~TargetGenerator(void)
{
	std::map<std::string, ATarget *>::iterator it_begin = this->aim.begin();
	std::map<std::string, ATarget *>::iterator it_end = this->aim.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->aim.clear();
	return ;
}

void	TargetGenerator::learnTargetType(ATarget *target_ptr)
{
	if (target_ptr)
		aim.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
	return ;
}

void	TargetGenerator::forgetTargetType(std::string const &target_type)
{
	aim.erase(target_type);
	return ;
}

ATarget *TargetGenerator::createTarget(std::string const &target_type)
{
	std::map<std::string, ATarget *>::iterator it = aim.find(target_type);
	if (it != aim.end())
		return aim[target_type];
	return NULL;
}
