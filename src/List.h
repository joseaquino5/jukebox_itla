/*
 * Lista.h
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#ifndef LIST_H_
#define LIST_H_
#include "Music.h"

namespace VMeta
{

	class List
	{
		private:
			Music* _first;
			Music* _last;
			bool _repeat;
		public:
			Music* erase(int index);
			bool isNull();
			void add(Music* music);
			int _length;
			List();
			virtual ~List();

			Music* getFirst() {return _first;}

			Music* getLast() {return _last;}

			void setRepeat(bool repeat)
			{
				if(_last != NULL && repeat){
					_last->setNext(_first);
				}else if (_last != NULL && !repeat){
					_last->setNext(NULL);
				}
				_repeat = repeat;
			}

			bool isRepeat() {return _repeat;}
};

} /* namespace VMeta */

#endif /* LIST_H_ */
