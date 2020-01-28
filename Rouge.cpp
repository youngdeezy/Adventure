/*****************************************                                      
 ** File:    Rogue.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Rogue file for
 ** the character parent class                                                     
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Rogue.h"

//calls upon character's contrusctor
Rogue::Rogue() : Character(" ", 0)
{
}

//calls upon character's constructor
Rogue::Rogue(string name, int hp):Character(name, hp){

}

//destructor
Rogue::~Rogue(){

}
//returns the damage done by the Wizard
int Rogue::SpecialAttack(){
    int damage = rand() % 12 + 2;
    cout << GetName() << "uses smite evil!";
    cout << GetName() << "attacks dealing " << damage << " damage!";
    return damage;
}