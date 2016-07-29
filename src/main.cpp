//============================================================================
// Name        : Vellonera.cpp
// Author      : VMeta
// Version     :
// Copyright   : Your copyright notice
// Description : Vellonera in C++, Ansi-style
//============================================================================
#include "Vellonera.h"

using namespace VMeta;



int main() {

	Vellonera* player = new Vellonera();
	while(true){
		if(!player->printMenu()){
			break;
		}
	}
	delete player;


	return 0;
}
