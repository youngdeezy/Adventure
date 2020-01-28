/*****************************************                                      
 ** File:    BabyDragon.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Baby Dragon file for
 ** the monster class                                                     
 **                                                                             
 **                                                                             
 ***********************************************/

#include "BabyDragon.h"

//default constructor that calls on Monster class
BabyDragon::BabyDragon():Monster(" ", 0){

}

//constructor that calls on Monster class
BabyDragon::BabyDragon(string name, int hp):Monster(name, hp){

}

//special attack for the class
int BabyDragon::SpecialAttack(){
    cout<< GetName() << " breathes a cone of fire at you!" << endl;
    cout<< GetName() << " deals 2 damage!" << endl;

    return 4;
}