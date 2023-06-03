/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:10:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 12:19:34 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
	return ;
}

TargetGenerator::~TargetGenerator(void)
{
	std::map<std::string, ATarget *>::iterator ini = this->arr_target.begin();
	while (ini != this->arr_target.end())
	{
		delete ini->second;
		++ini;
	}
	this->arr_target.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target_ptr)
{
	if (target_ptr)
		arr_target.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &type_name)
{
	std::map<std::string, ATarget *>::iterator search = arr_target.find(type_name);
	if (search != arr_target.end())
		delete search->second;
	arr_target.erase(type_name);
}

ATarget	*TargetGenerator::createTarget(std::string const &type_name)
{
	std::map<std::string, ATarget *>::iterator search = arr_target.find(type_name);
	if (search != arr_target.end())
		return arr_target[type_name];
	return NULL;
}
