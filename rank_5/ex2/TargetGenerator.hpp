/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:10:21 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/03 12:19:39 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &src);
		TargetGenerator &operator=(TargetGenerator const &src);

		std::map<std::string, ATarget *> arr_target;

	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void	learnTargetType(ATarget *target_ptr);
		void	forgetTargetType(std::string const &type_name);
		ATarget	*createTarget(std::string const &type_name);
};

#endif
