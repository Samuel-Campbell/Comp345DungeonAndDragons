/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CharacterObserver.h
 * Author: Vanessa
 *
 * Created on November 6, 2016, 6:13 PM
 */

#ifndef CHARACTEROBSERVER_H
#define CHARACTEROBSERVER_H

#include "observer.h"




class CharacterObserver: public Observer{
public:
    //CharacterObserver();
    //CharacterObserver(Hero* _character);
    ~CharacterObserver();
    void Update();
    void display();
private:

};

#endif /* CHARACTEROBSERVER_H */
