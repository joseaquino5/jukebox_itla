/*
 * Vellonera.cpp
 *
 *  Created on: 27 jul. 2016
 *      Author: VMeta
 */

#include "Vellonera.h"

namespace VMeta {

	Vellonera::Vellonera() : _list(new List()), _current(NULL)
	{


	}
	bool Vellonera::printMenu()
	{
	  cout <<"\n\n\t\t\tWelcome to Vellonera\n"<< endl;
	  cout <<"You have to choose an option (Type the number of the option do you want to execute): \n"<< endl;
	  cout <<"1. Add new music"<< endl;
	  cout <<"2. visualize all musics"<< endl;
	  cout <<"3. Show current music"<< endl;
	  cout <<"4. Next music"<< endl;
	  cout <<"5. Before music"<< endl;
	  cout <<"6. Turn repeat on/off the list"<< endl;
	  cout <<"7. Delete music"<< endl;
	  cout <<"8. Exit"<< endl;
	  cout <<"\nType your option: ";
	  getline(cin, _option);
	  cout << endl;
	  return  verifyOption();

	}

	bool Vellonera::verifyOption() {
        while(!(_option == "1" || _option == "2" || _option == "3" || _option == "4" || _option == "5"  || _option == "6"  || _option == "7"   || _option == "8")){
        	cout <<"Try again please you type an invalid option: ";
        	getline(cin, _option);
         }

        if(_option == "1"){
        	addMusic();
        	return true;
        }
        else if(_option == "2"){
        	visualizeMusics();
        	return true;
        }

        else if(_option == "3"){
        	showCurrentMusic();
        	return true;
        }
        else if(_option == "4"){
        	nextMusic();
        	return true;
        }
        else if(_option == "5"){
        	beforeMusic();
        	return true;
        }
        else if(_option == "6"){
        	TurnOnOffrepeat();
        	return true;
        }
        else if(_option == "7"){
        	deleteMusic();
        	return true;
        }
        else{
        	cout << "See, back soon" << endl;
        	return false;
        }
	}

	Music* Vellonera::formMusic(Music* music) {
		cout <<"Music's title: ";
		getline(cin, _option);
		music->setTitle(_option);
		cout << "Music's name artist: ";
		getline(cin, _option);
		music->setArtistName(_option);
		cout <<"Music's duration (format 0:00): ";
		getline(cin, _option);
		while(!music->isValidDuration(_option)){
			cout <<"Try again please you type an invalid duration, remember your duration format(0:00): ";
			getline(cin, _option);
		}
		music->setDuration(_option);
		return music;
	}

	void Vellonera::addMusic()
	{
		cout <<"Entering music"<< endl;
		_list->add(formMusic(new Music()));
		cout <<"Music Added. Press ENTER to return to the main menu...";
	    cin.ignore();
	}

	void Vellonera::visualizeMusics()
	{

		if(hasMusic()){
			cout <<"Musics List: "<< endl;
			printAllMusics();
			cout <<"Press enter to continue..";
			cin.ignore();
		}

	}

	bool Vellonera::hasMusic() {
		if(_list->isNull()){
			cout <<"You don't have any musics in your vallonera, you'll be return to the main menu."<< endl;
			cout <<"Press enter to continue..";
		    cin.ignore();
		    return false;
		}else{
			return true;
		}
	}

	void Vellonera::printAllMusics()
	{
		Music* iterator = _list -> getFirst();
		int i = 1;
		while(iterator != NULL){
			cout << i << ") " << iterator ->getTitle() <<  ", " <<  iterator->getArtistName() << " " << iterator->getDuration() << endl;

			if(iterator == _list->getLast()){
				break;
			}
			iterator = iterator->getNext();
			i++;
		}
		cout <<  endl;
	}

	void Vellonera::printMusic(Music* music) {
		if(music != NULL){
			cout << "--> " << music ->getTitle() <<  ", " <<  music->getArtistName() << " " << music->getDuration() << endl << endl;
		}else{
			cout <<"You don't have current music now.";
		}
		cout <<"Press enter to continue..";
		cin.ignore();
	}


	void Vellonera::showCurrentMusic()
	{
		if(hasMusic()){
			cout <<"Current Music: "<< endl;
			if(_current == NULL)
			{
				_current = _list-> getFirst();
			}
			printMusic(_current);
		}
	}

	void Vellonera::nextMusic()
	{
		if(hasMusic()){
			if(_current == NULL){_current = _list-> getFirst();}
			cout << "Advancing to the next track ..." << endl;
			if(_current-> getNext() != NULL){
				_current = _current-> getNext();
				cout <<"Current Music: "<< endl;
			}else{
				cout << "You've reached the end of your list, if you want to proceed to the next music you should activate repetition of list." << endl;
				cout <<"Your current music is: "<< endl;
			}
			printMusic(_current);

		}
	}

	void Vellonera::beforeMusic()
	{
		if(hasMusic()){
			if(_current == NULL){_current = _list-> getFirst();}
			cout << "Going back to the previous track ..." << endl;
			if(_current-> getBefore() != NULL){
				_current = _current-> getBefore();
				cout <<"Current Music: "<< endl;
			}else{
				cout << "You've reached the start of your list, You can not go back more." << endl;
				cout <<"Your current music is: "<< endl;
			}
			printMusic(_current);

		}
	}

	void Vellonera::TurnOnOffrepeat()
	{
		if(_list->isRepeat()){
			cout << "Repeat on disabled list." << endl;
			_list->setRepeat(false);
		}else{
			cout << "Activated repeat list." << endl;
			_list->setRepeat(true);
		}
		cin.ignore();
	}

	void Vellonera::deleteMusic()
	{
		if(hasMusic()){
			cout <<"Eliminated musics:"<< endl;
			printAllMusics();
			cout <<"Select the music' number to delete: ";
			getline(cin, _option);
			int indice =  atoi(_option.c_str());
			Music* musicToDelete = _list->erase(indice);
			while(!musicToDelete){
				cout <<"Try again please you type an invalid index: ";
				getline(cin, _option);
				musicToDelete = _list->erase(atoi(_option.c_str()));
			}
			cout <<"Music deleted. ";
			if(musicToDelete == _current){
				cout <<"Have deleted the current music, your current music now is:"<<endl;
				if(musicToDelete->getNext() != NULL){_current = musicToDelete->getNext();} else { _current = _list->getFirst();}
				printMusic(_current);
			}else{
				cout<<"Press ENTER to return to the main menu...";
			}
			delete musicToDelete;
		    cin.ignore();
		}

	}

	Vellonera::~Vellonera()
	{
		Music* iterator = _list -> getFirst();
		while(iterator != NULL){
			delete iterator;
			iterator = iterator->getNext();
		}
		delete _list;
		delete _current;
	}

} /* namespace VMeta */
