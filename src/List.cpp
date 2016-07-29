/*
 * Lista.cpp
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#include "List.h"
#include "utils.h"
namespace VMeta {

	List::List() : _first(NULL), _last(NULL), _repeat(false),  _length(0)
	{

	}

	void List::add(Music* music)
	{
		if(_first == NULL)
		{
			_first = music;
			_last = music;
			if(_repeat){
				_last->setNext(_first);
			}
		}else
		{
			Music* iterator = _first;
			Music* aux;
			int i = 0, posicionTocante = 0;

			while (iterator != NULL){
				i++;
				if(VMeta::durationToInt(music->getDuration()) < VMeta::durationToInt(iterator->getDuration())){
					posicionTocante = i;
					if(i == 1){
						music->setNext(_first);
						_first->setBefore(music);
						_first = music;
						break;
					}

					aux = iterator;
					break;
				}
				iterator = iterator->getNext();
			}

			if (posicionTocante == 0){
				_last -> setNext(music);
				music -> setBefore(_last);
				_last = music;
				if(_repeat){
					_last->setNext(_first);
				}
			}else if(i > 1){
				music->setNext(aux);
				music->setBefore(aux->getBefore());
				aux->getBefore()->setNext(music);
				aux->setBefore(music);
			}

		}
		_length++;
	}

	bool List::isNull()
	{
		return !_first ? true : false;
	}

	Music* List::erase(int index)
	{
		Music* musicToDelete;
		if(index == 1){
			musicToDelete = _first;
			if(_first -> getNext() == _first){
				_first = NULL;
			}else{
				_first = _first -> getNext();
			}
			_length--;
			return musicToDelete;
		}
		else{
			int i = 1;
			Music* iterator = _first;
			while(iterator != NULL){
				if(i == index){
					iterator->getBefore()->setNext(iterator->getNext());
					if(iterator->getNext() != NULL && iterator->getNext()  != _first){
						iterator->getNext()-> setBefore(iterator->getBefore());
					}
					_length--;
					return iterator;
				}
				iterator = iterator -> getNext();
				i++;
			}
		}
		return NULL;
	}

	List::~List()
	{

	}

} /* namespace VMeta */
