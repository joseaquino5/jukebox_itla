/*
 * Music.h
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#ifndef MUSIC_H_
#define MUSIC_H_
#include <iostream>
#include <cstdlib>
#include <sstream>

namespace VMeta {

	class Music
	{
		private:
			std::string _title;
			std::string _artistName;
			std::string _duration;
			Music* _before;
			Music* _next;
		public:
			Music();
			virtual ~Music();
			bool isValidDuration(std::string duration);

			std::string getArtistName() {return _artistName;}

			void setArtistName(std::string artistName) {_artistName = artistName;}

			Music* getBefore() {return _before;}

			void setBefore(Music* before) {_before = before;}

			std::string getDuration() {return _duration;}

			void setDuration(std::string  duration) {_duration = duration;}

			Music* getNext() {return _next;}

			void setNext(Music* next) {_next = next;}

			std::string getTitle() {return _title;}

			void setTitle(std::string title) {_title = title;}
};

} /* namespace VMeta */

#endif /* MUSIC_H_ */
