/*
 * Music.cpp
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#include "Music.h"
#include "utils.h"

namespace VMeta
{

	Music::Music() : _before(NULL), _next(NULL)
	{


	}

	Music::~Music()
	{

	}

	bool Music::isValidDuration(std::string duration) {
		int durationLength = duration.length();
		int time = atoi(VMeta::str_replace(duration, std::string(":"), std::string("")).c_str());
		return time != 0 && durationLength > 3 && duration[durationLength-3] == ':'? true : false;

	}

} /* namespace VMeta */
