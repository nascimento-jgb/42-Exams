/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:55:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 10:21:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_H
# define WARLOCK_H

#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

		Warlock(void);
		Warlock(Warlock const &src);
		Warlock	&operator=(Warlock const &src);

		std::map<std::string, ASpell *> stash;

	public:
	//Canonical Form
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

	//Getter and Setter
		std::string const &getTitle(void) const;
		void	setTitle(std::string const title);
		std::string const &getName(void) const;

		void	introduce(void) const;

		void	learnSpell(ASpell *aspell_ptr);
		void	forgetSpell(std::string spell_name);
		void	launchSpell(std::string spell_name, ATarget const &target_ref);
};

#endif
