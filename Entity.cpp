/*****************************************                                      
 ** File:    Entity.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   The main parent file for all the other classes
      in the project.                                                 
 **                                                                             
 **                                                                             
 ***********************************************/
#include "Entity.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//default constructor
Entity::Entity(){
    m_name = " ";
    m_health = 0;
    m_level = 0;    
}

//constructor with string and int arg
Entity::Entity(string name , int health){

    m_name = name;
    m_health = health;
    m_level = 0;


}

//destructor
Entity::~Entity(){

}

//returns name
string Entity::GetName(){
    return m_name;
}

//returns an int representing health
int Entity::GetHealth(){
    return m_health;
}

//sets the name of entity
void Entity::SetName(string name){
    m_name = name;
}

//sets the helath of entity
void Entity::SetHealth(int health){
    m_health = health;
}