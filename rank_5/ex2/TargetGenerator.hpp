#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &src);
		TargetGenerator &operator=(TargetGenerator const &src);

		std::map <std::string, ATarget *> aim;

	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void	learnTargetType(ATarget *target_ptr);
		void	forgetTargetType(std::string const &target_type);
		ATarget *createTarget(std::string const &target_type);
};
#endif
