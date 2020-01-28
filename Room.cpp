/*****************************************                                      
 ** File:    Room.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
    Room class used for the rooms the map for the 
    game.                                                   
 **                                                                             
 **                                                                             
 ***********************************************/

#include "Room.h"

//Room
//creates a Room with the given arguments
Room::Room(int id, string name, 
string desc, int north, int east, int south, int west){
    m_ID = id;
    m_name = name;
    m_desc = desc;
    m_direction[n] = north;
    m_direction[e] = east;
    m_direction[s] = south;
    m_direction[w] = west;
}

//GetName
//returns the name of the room
string Room::GetName(){
    return m_name;
}

//GetID
//returns the ID of the room
int Room::GetID(){
    return m_ID;
}

//GetDesc
//returns the description of the room
string Room::GetDesc(){
    return m_desc;
}

//CheckDirection
//returns the number that poits to the next room 
//given a char
int Room::CheckDirection(char myDirection){

    //if myDirection is north, then it retruns the Id of
    //the room it is pointing towards
    if(myDirection == 'n' || myDirection == 'N'){

        if(m_direction[n] != -1){
            return m_direction[n];
        }
       
    }

    //if myDirection is east, then it retruns the Id of
    //the room it is pointing towards
    else if(myDirection == 'e' || myDirection == 'E'){
        if(m_direction[e] != -1){
            return m_direction[e];
        }
        
        
    }

    //if myDirection is west, then it retruns the Id of
    //the room it is pointing towards
    else if(myDirection == 'w' || myDirection == 'W'){

        if(m_direction[w] != -1){

            return m_direction[w];
        }
        
    }

    //if myDirection is south, then it retruns the Id of
    //the room it is pointing towards
    else if(myDirection == 's' || myDirection == 'S'){

        if(m_direction[s] != -1){

            return m_direction[s];
        }
        
    }

    //default 
    return -1;
}

//PrintRoom
//prints out the characteristics of the room
void Room::PrintRoom(){

    cout << m_name << endl;
    cout << m_desc << endl;
    cout << "posible exits: " << endl;
    
    if(m_direction[0] != -1){
        cout << "N"<< endl;
    }

    if(m_direction[1] != -1){
        cout << "E"<< endl;
    }

    if(m_direction[2] != -1){
        cout << "S" << endl;
    }

    if(m_direction[3] != -1){
        cout << "W" << endl;
    }
    
    

}