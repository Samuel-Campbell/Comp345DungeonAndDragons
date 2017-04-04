/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CharacterObserver.cpp
 * Author: Vanessa
 *
 * Created on November 6, 2016, 6:13 PM
 */
#include "characterobserver.h"
#include "character.h"
#include <iostream>

using namespace std;

/*
CharacterObserver::CharacterObserver(Hero* _aCharacter) {
    //initialization of the object and we attach the observer to the character
    _character = _aCharacter;
    _character->Attach(this);
}
CharacterObserver:: ~CharacterObserver() {
    //detach observer from character
    _character->Detach(this);
}

void CharacterObserver::display(){
    cout << "*** CHARACTER STATS HAVE BEEN UPDATED ***" << endl;
	_character->displayStats();
}

void CharacterObserver::Update(){
    // called by Notify() when the state of the Subject (character) changes
    this->display();
}
*/