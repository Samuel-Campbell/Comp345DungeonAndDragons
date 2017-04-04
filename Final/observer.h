/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Observer.h
 * Author: Vanessa
 *
 * Created on November 4, 2016, 10:20 AM
 */

#ifndef OBSERVER_H
#define OBSERVER_H
#include "subject.h"

class Subject;

class Observer {
public:
    Observer();
    ~Observer();
    virtual void Update() = 0;

};

#endif /* OBSERVER_H */
