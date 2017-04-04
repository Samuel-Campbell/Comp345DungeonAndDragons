/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SUBJECT_H
#define SUBJECT_H
#include "subject.h"
#include "observer.h"
#include <vector>
#include <iostream>

Subject::Subject(){
    observerViews = vector<Observer*>();
}
Subject::~Subject(){
}

void Subject::Attach(Observer* o){
    observerViews.push_back(o);
}
void Subject::Detach(Observer* o){
    int count = observerViews.size();
    int i =0;

    for( i = 0 ; i < count; i++){
        if (observerViews[i] == o)
        {
            observerViews.erase(observerViews.begin() + i);

        }
    }

}
//updates all the subjects that have updated
void Subject::Notify(){
    for (int i = 0; i < observerViews.size(); i++){
        observerViews[i]->Update();
    }
}

#endif
