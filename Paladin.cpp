/*****************************************                                      
 ** File:    Paladin.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   Paladin class, used for the game. Parent class
 **  is character.                                                 
 **                                                                             
 **                                                                             
 ***********************************************/
#include "Paladin.h"

//constructor used for Paladin, calls upon Character
Paladin::Paladin():Character(" ", 0){

}

//constructor used for Paladin with args, calls upon Character
Paladin::Paladin(string name, int hp):Character(name, hp){

}

//destructor
Paladin::~Paladin(){

}

//special attack for paladin, returns damage
int Paladin::SpecialAttack(){
    int damage = rand() % 8 + 1;
    cout << GetName() << " uses smite evil!";
    cout << GetName() << " attacks dealing " << damage << " damage!";
    return damage;
}