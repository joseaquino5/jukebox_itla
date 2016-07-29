/*
 * Utils.cpp
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#include "utils.h"
namespace VMeta {
	std::string str_replace(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}
	int durationToInt(std::string duration) {
		return atoi(str_replace(duration, std::string(":"), std::string("")).c_str());
	}
}
