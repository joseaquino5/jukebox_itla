/*
 * Vellonera.h
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#ifndef VELLONERA_H_
#define VELLONERA_H_
#include <string>

#include "List.h"
#include "Music.h"

using namespace std;
namespace VMeta {

	class Vellonera
	{
		private:
			List* _list;
			Music* _current;
			string _option;
		public:
			void TurnOnOffrepeat();
			void beforeMusic();
			void nextMusic();
			void showCurrentMusic();
			void printMusic(Music* music);
			void printAllMusics();
			bool hasMusic();
			void visualizeMusics();
			Music* formMusic(Music* music);
			void deleteMusic();
			void addMusic();
			bool printMenu();
			bool verifyOption();
			Vellonera();
			virtual ~Vellonera();
	};

	} /* namespace VMeta */

#endif /* VELLONERA_H_ */
