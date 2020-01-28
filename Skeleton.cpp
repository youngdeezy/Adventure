/*****************************************                                      
 ** File:    Skeleton.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Skeleton file for
 ** the monster parent class                                                     
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Skeleton.h"

//calls upon Monster's constructor
Skeleton::Skeleton():Monster(" ", 0){

}

//calls upon Monster's constructor
Skeleton::Skeleton(string name, int hp):Monster(name, hp){

}

//returns the amount of damage that the skeleton does, returns 1
int Skeleton::SpecialAttack(){

    cout<< GetName() << " bashes you with its own arm!" << endl;
    cout << GetName() << " deals 1 damage!" << endl;

    return 1;
}