/*****************************************                                      
 ** File:    Monster.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the monster file for
 ** the entity parent class                                       
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Monster.h"

//calls upon entity constructor
Monster::Monster():Entity(" ", 0){

}

//calls upon entity constructor
Monster::Monster(string name, int hp):Entity(name, hp){

}

//calls monsters attack on players, returns damage
int Monster::Attack(){
    cout<< GetName() << "1 point of damage!" << endl;
    return 1;
}