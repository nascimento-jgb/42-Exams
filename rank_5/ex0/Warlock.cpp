/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:05:19 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/02 13:23:12 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(void)
{
	return ;
}

Warlock::Warlock(Warlock const &src)
{
	_name = src._name;
	_title = src._title;
	return ;
}

Warlock &Warlock::operator=(Warlock const &src)
{
	this->_name = src._name;
	this->_title = src._title;
	return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
	return ;
}

Warlock::~Warlock(void)
{
	std::cout << _name << ": My job here is done!" << std::endl;
	return ;
}

std::string const &Warlock::getTitle(void) const
{
	return (_title);
}

void	Warlock::setTitle(std::string const title)
{
	_title = title;
	return ;
}

std::string const &Warlock::getName(void) const
{
	return (_name);
}

void	Warlock::introduce(void) const
{
	std::cout << _name << ": I am "<< _name << ", " << _title << "!" << std::endl;
}
