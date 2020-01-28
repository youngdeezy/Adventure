/*****************************************                                      
 ** File:    Goblin.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Goblin file for
 ** the monster parent class                                                     
 **                                                                             
 **                                                                             
 ***********************************************/
#include "Goblin.h"

//default constructor that calls up Monster parent class
Goblin::Goblin():Monster(" ", 0){

}

//contructor with args that calls upon monster constructor
Goblin::Goblin(string name, int hp):Monster(name, hp){

}

//speical attack for goblin, returns the damage done
int Goblin::SpecialAttack(){
    cout<< GetName() << " knaws at your ankles!" << endl;
    cout<< GetName() << " deals 2 damage!" << endl;

    return 2;
}