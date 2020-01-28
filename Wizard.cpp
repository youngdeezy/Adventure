/*****************************************                                      
 ** File:    Wizard.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Wizard file for
 ** the Character parent class                                                   
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Wizard.h"

//constructor that calls upon character's constructor
Wizard::Wizard():Character(" ", 0){

}

//constructor that calls upon character's constructor
Wizard::Wizard(string name, int hp):Character(name, hp){

}

//destructor
Wizard::~Wizard(){

}

//special attack for Wizard, returns damage done
int Wizard::SpecialAttack(){
    int damage = rand() % 12 + 3;
    cout << GetName() << " casts magic missle!";
    cout << GetName() << " attacks dealing " << damage << " damage!";
    return damage;
}