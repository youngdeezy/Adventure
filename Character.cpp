/*****************************************                                      
 ** File:    Character.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file is for the Character class used for
      the other characters, child class of entity                                                   
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Character.h"

//constructor calling upon Entity
Character::Character():Entity(" ", 0){


}

//constructor calling upon Entity
Character::Character(string name, int hp):Entity(name, hp){

}


Character::~Character(){

}

//returns the damage done as an int
int Character::Attack(){
    int damage = rand() % 6 + 1;
    cout << GetName() << "attacks dealing " << damage << " damage!" << endl;
    return damage;
}

//Character does not have special attack, calls upon attack
int Character::SpecialAttack(){
    cout << GetName() << "Does not have special attack" << endl;
    Attack();
}
