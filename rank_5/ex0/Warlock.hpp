#ifndef WARLOCK_H
# define WARLOCK_H

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;

		Warlock(void);
		Warlock(Warlock const &src);
		Warlock &operator=(Warlock const &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);

		std::string const &getName(void) const;
		std::string const &getTitle(void) const;
		void	setTitle(std::string const &title_ref);

		void	introduce(void) const;
};

#endif
