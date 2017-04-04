/*
 * File:   Subject.h
 * Author: Vanessa
 *
 * Created on November 3, 2016, 10:58 PM
 */

#ifndef Subject_h
#define Subject_h

#include "observer.h"
#include <vector>

using namespace std;

class Observer;

class Subject{
    public:
        //methods declaration
        virtual void Attach(Observer *o);
        virtual void Detach(Observer *o);
        virtual void Notify();

        //constructor declaration
        Subject();
        ~Subject();

    protected:
        vector <Observer *> observerViews;
};

#endif
