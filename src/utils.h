/*
 * Utils.h
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#include <iostream>
#include <cstdlib>
namespace VMeta {
std::string str_replace(std::string str, const std::string& from, const std::string& to);
int durationToInt(std::string duration);
}
