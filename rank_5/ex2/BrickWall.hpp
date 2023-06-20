#ifndef BRICKWALL_H
# define BRICKWALL_H

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall(void);
		~BrickWall(void);

		ATarget *clone(void) const;
};

#endif
