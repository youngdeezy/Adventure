/*****************************************                                      
 ** File:    Game.cpp
 ** Project: CMSC 202 Project 4, Fall 2019                                     
 ** Author:  Diego Burgos                                                       
 ** Date:    10/29/2019                                                         
 ** Section: 30                                                                 
 ** E-mail:  dburgos2@umbc.edu                                                  
 **                                                                             
 **   This file contains the Game file, which contains
    the functions and variables used to set the game up                                                   
 **                                                                             
 **                                                                             
 ***********************************************/
#include "Game.h"



//default constructor
Game::Game()
{

    m_curRoom = START_ROOM;
    m_numSpecial = NUM_SPECIAL;
    m_numRests = NUM_RESTS;
    string file;
    cout << "Welcome to UMBC Adventure!" << endl;
    cout << "What file would you like to load?" << endl;
    cin >> file;
    LoadMap(file);
    CharacterCreation();
    StartGame();
    
}

//contrusctor with name as argument
//string is used for the file of name
Game::Game(string name)
{

    m_curRoom = START_ROOM;
    m_numSpecial = NUM_SPECIAL;
    m_numRests = NUM_RESTS;

    cout << "Welcome to UMBC Adventure!" << endl;
    //cout<<"What file would you like to load?" << endl;
    LoadMap(name);
    CharacterCreation();
    StartGame();
}

//desctructor
Game::~Game()
{

    m_myMap.clear();
    delete m_myCharacter;
    delete m_curMonster;
    //m_myCharacter = nullptr;
    //m_curMonster = nullptr;
}

//LoadMap
//loads the rooms from the file onto the 
void Game::LoadMap(string name)
{

    //values set for the foundables

    string line;

    string ID;
    string roomName;
    string desc;

    int counter = 0;
    ifstream myFile(name);

    string dir;
    Room *tempRoom;

    //cout << "Hello" << endl;

    //goes across each line and sets the values for the DecayList that is set apart by semicolon
    while (myFile)
    {

        getline(myFile, ID, '|');
        int idNum = atoi(ID.c_str());
        getline(myFile, roomName, '|');
        getline(myFile, desc, '|');
        getline(myFile, dir, '|');
        int north = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int east = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int south = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int west = atoi(dir.c_str());
        if (myFile.eof())
        {
            break;
        }
        tempRoom = new Room(idNum, roomName, desc, north, east, south, west);
        m_myMap.push_back(tempRoom);

        //delte this after
    }
    delete tempRoom;
    myFile.close();
}

//CharacterCreation
//creates a character to use for the game
void Game::CharacterCreation()
{

    string name;
    int selectedClass;
    cout << "Character name: ";
    cin >> name;
    cout << endl;
    cout << "Select a class" << endl;
    cout << "1. Rogue" << endl;
    cout << "2. Wizard" << endl;
    cout << "3. Paladin" << endl;
    cout << "4. No Classs" << endl;
    cin >> selectedClass;
    Character* temp;

    //a character is generated depending on the input
    switch (selectedClass)
    {
    case 1:
        m_myCharacter = new Rogue(name, ROGUE_HEALTH);
        break;
    case 2:
        m_myCharacter = new Wizard(name, WIZARD_HEALTH);
        break;
    case 3:
        m_myCharacter = new Paladin(name, PALADIN_HEALTH);
        break;
    case 4:
        m_myCharacter = new Character(name, 10);
        break;
    }
}

//StartGame
//starts the game 
void Game::StartGame()
{

    bool healthCheck = true;
    m_myMap.at(m_curRoom)->PrintRoom();
    RandomMonster();

    //checks to see if player health is above 0
    //game ends if it is below that
    while (healthCheck == true)
    {
        if (m_myCharacter->GetHealth() < 1)
        {
            healthCheck = false;
            cout << m_myCharacter->GetName() << " has been defeated" << endl;
            cout << "Exiting game " << endl;
            exit(0);
        }

        Action();


    }
}

//sets the actions a player can do in the game
void Game::Action()
{

    int inputNum;
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Monster" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> inputNum;

    //input determines what the player will do
    switch (inputNum)
    {
    case 1:
        m_myMap.at(m_curRoom)->PrintRoom();
        break;
    case 2:
        Move();
        break;
    case 3:
        Attack();
        break;
    case 4:
        //checks to see if a player can rest
        if(m_numRests >= NUM_RESTS && m_curMonster == NULL){
        cout << "Resting..." << endl;
        m_numRests--;
        m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
        }
        
        else if(NUM_RESTS > m_numRests){
            cout << "Rests already used up" << endl;
        }
        else if(m_curMonster != NULL){
            cout << "Cannot rest here" << endl;
        }
        break;
    case 5:
        Stats();
        break;
    case 6:
        //exits the game
        cout << "Exiting" << endl;
        delete m_curMonster;
        delete m_myCharacter;
        m_myMap.clear();
        exit(0);
        break;
    }
}

//RandomMonster
//Generates a monster for the room
Entity *Game::RandomMonster()
{

    Monster *gob;
    int randGen = rand() % 4 + 1;

    //randGen randomly chooses either a monster or nothing at all
    switch (randGen)
    {
    case 1:
    {
        gob = NULL;
        m_curMonster = gob;
        cout << "It is peaceful here" << endl;
        return m_curMonster;
    }
    case 2:
    {
        gob = new Goblin("Goblin", GOBLIN_HEALTH);
        m_curMonster = gob;
        cout << "A goblin is picking his nose" << endl;
        return m_curMonster;
    }
    case 3:
    {
        gob = new Skeleton("Skeleton", SKELETON_HEALTH);
        m_curMonster = gob;
        cout << "A skeleton lumbers around the room" << endl;
        return m_curMonster;
    }
    case 4:
    {
        gob = new BabyDragon("Baby Dragon", DRAGON_HEALTH);
        m_curMonster = gob;
        cout << "A Baby Dragon flies through the air" << endl;
        return m_curMonster;
    }
    }


    return m_curMonster;
}

//Move 
//determines where the player can move in the m_myMap vector
void Game::Move()
{

    char direction;

    cout << "Which direction? " << endl;
    cin >> direction;
    int dirNum = m_myMap.at(m_curRoom)->CheckDirection(direction);

    //if it is not -1, then the dirNum is set as the current room
    //makes a new Monster 
    if (dirNum != -1)
    {
        m_curRoom = dirNum;
        m_myMap.at(m_curRoom)->PrintRoom();
        delete m_curMonster;
        RandomMonster();
    }
    else
    {

        cout << "You cannot move there!" << endl;
    }
}

//Attack
//method to determine the conditions for attacking
void Game::Attack()
{
    //if there are no monsters, it returns
    if (m_curMonster == NULL)
    {
        cout << "There is nothing to attack in this room" << endl;
        return;
    }

    int attackNum = 0;
    bool defeated = false;

    //loops until defeated is true, whether it is a player or monster
    while (defeated == false)
    {
        
        cout << "1. Normal Attack" << endl;
        cout << "2. Special Attack" << endl;
        cin >> attackNum;

        switch (attackNum)
        {
        case 1:
            attackNum = m_myCharacter->Attack();
            m_curMonster->SetHealth(m_curMonster->GetHealth() - attackNum);

            break;

        case 2:

            attackNum = m_myCharacter->SpecialAttack();
            m_curMonster->SetHealth(m_curMonster->GetHealth() - attackNum);

            break;
        }

        int randomNum = rand() % 4 + 1;

        
        if (m_curMonster->GetHealth() < 1)
        {
            cout << m_curMonster->GetName() << " has been defeated.";
            m_curMonster = NULL;
            defeated = true;
        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Goblin")
        {

            
            attackNum = m_curMonster->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);

        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Skeleton")
        {

            attackNum = m_curMonster->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);

        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Baby Dragon")
        {

            attackNum = m_curMonster->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);
        }
        else
        {
            attackNum = m_curMonster->Attack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);
        }

        if (m_myCharacter->GetHealth() < 1)
        {
            
            defeated = true;
        }

        //doesn't print out if something has been defeated
        if (defeated == false)
        {
            cout << m_myCharacter->GetName() << "'s HP:" << m_myCharacter->GetHealth() << endl;
            cout << m_curMonster->GetName() << "'s HP:" << m_curMonster->GetHealth() << endl;
        }

        
        //delete the pointers
    }
}

//Stats
//prints about player information
void Game::Stats()
{

    cout << "Name: " << m_myCharacter->GetName() << endl;
    cout << "HP: " << m_myCharacter->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Special: " << m_numSpecial << endl;
}


/*
#include "Game.h"

//bool health = true;
Game::Game()
{

    m_curRoom = START_ROOM;
    m_numSpecial = NUM_SPECIAL;
    m_numRests = NUM_RESTS;
    string file;
    cout << "Welcome to UMBC Adventure!" << endl;
    cout << "What file would you like to load?" << endl;
    cin >> file;
    LoadMap(file);
    CharacterCreation();
    StartGame();
}

Game::Game(string name)
{

    m_curRoom = START_ROOM;
    m_numSpecial = NUM_SPECIAL;
    m_numRests = NUM_RESTS;

    cout << "Welcome to UMBC Adventure!" << endl;
    //cout<<"What file would you like to load?" << endl;
    LoadMap(name);
    CharacterCreation();
    StartGame();
}

Game::~Game()
{

    m_myMap.clear();
    delete m_myCharacter;
    delete m_curMonster;
    m_myCharacter = nullptr;
    m_curMonster = nullptr;
}

void Game::LoadMap(string name)
{

    //values set for the foundables

    string line;

    string ID;
    string roomName;
    string desc;
    //string dirN;
    //string dirE;
    //string dirS;
    //string dirW;

    int counter = 0;
    ifstream myFile(name);
    //string north;
    string dir;
    //string east;
    //string south;
    //string west;

    //cout << "Hello" << endl;

    //goes across each line and sets the values for the DecayList that is set apart by semicolon
    while (myFile)
    {

        getline(myFile, ID, '|');
        int idNum = atoi(ID.c_str());
        getline(myFile, roomName, '|');
        getline(myFile, desc, '|');
        getline(myFile, dir, '|');
        int north = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int east = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int south = atoi(dir.c_str());
        getline(myFile, dir, '|');
        int west = atoi(dir.c_str());
        if (myFile.eof())
        {
            break;
        }
        Room *tempRoom = new Room(idNum, roomName, desc, north, east, south, west);
        m_myMap.push_back(tempRoom);

        //delte this after
    }

    myFile.close();
}

void Game::CharacterCreation()
{

    string name;
    int selectedClass = 0;
    cout << "Character name: ";
    cin >> name;
    cout << endl;
    while (selectedClass > 1 && selectedClass < 5)
    {
        cout << "Select a class" << endl;
        cout << "1. Rogue" << endl;
        cout << "2. Wizard" << endl;
        cout << "3. Paladin" << endl;
        cout << "4. No Classs" << endl;
        cin >> selectedClass;
    }

    switch (selectedClass)
    {
    case 1:
        m_myCharacter = new Rogue(name, ROGUE_HEALTH);
        break;
    case 2:
        m_myCharacter = new Wizard(name, WIZARD_HEALTH);
        break;
    case 3:
        m_myCharacter = new Paladin(name, PALADIN_HEALTH);
        break;
    case 4:
        m_myCharacter = new Character(name, 10);
        break;
    }
}

void Game::StartGame()
{

    bool healthCheck = true;
    m_myMap.at(m_curRoom)->PrintRoom();
    RandomMonster();

    while (healthCheck == true)
    {
        if (m_myCharacter->GetHealth() < 1)
        {
            healthCheck = false;
            cout << m_myCharacter->GetName() << " has been defeated" << endl;
            cout << "Exiting game " << endl;
            exit(0);
        }

        Action();
    }
}
void Game::Action()
{

    int inputNum = 0;
    while (inputNum > 1 && inputNum < 5)
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Monster" << endl;
        cout << "4. Rest" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> inputNum;
    }

    switch (inputNum)
    {
    case 1:
        m_myMap.at(m_curRoom)->PrintRoom();
        break;
    case 2:
        Move();
        break;
    case 3:
        Attack();
        break;
    case 4:
        if (m_numRests >= NUM_RESTS && m_curMonster == NULL)
        {
            cout << "Resting..." << endl;
            m_numRests--;
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() + REST_HEAL);
        }

        else if (NUM_RESTS > m_numRests)
        {
            cout << "Rests already used up" << endl;
        }
        else if (m_curMonster != NULL)
        {
            cout << "Cannot rest here" << endl;
        }
        break;
    case 5:
        Stats();
        break;
    case 6:
        cout << "Exiting" << endl;
        exit(0);
        break;
    }
    inputNum = 0;
}

Entity *Game::RandomMonster()
{

    Monster *gob;
    int randGen = rand() % 4 + 1;

    switch (randGen)
    {
    case 1:
    {
        gob = NULL;
        m_curMonster = gob;
        cout << "It is peaceful here" << endl;
        return m_curMonster;
    }
    case 2:
    {
        gob = new Goblin("Goblin", GOBLIN_HEALTH);
        m_curMonster = gob;
        cout << "A goblin is picking his nose" << endl;
        return m_curMonster;
    }
    case 3:
    {
        gob = new Skeleton("Skeleton", SKELETON_HEALTH);
        m_curMonster = gob;
        cout << "A skeleton lumbers around the room" << endl;
        return m_curMonster;
    }
    case 4:
    {
        gob = new BabyDragon("Baby Dragon", DRAGON_HEALTH);
        m_curMonster = gob;
        cout << "A Baby Dragon flies through the air" << endl;
        return m_curMonster;
    }

    }

    m_curMonster = gob;
    //delete gob;
    return m_curMonster;
}

void Game::Move()
{

    char direction = ' ';

    while(direction != 'n' || direction != 'e' || direction != 's' || direction != 'w' || 
    direction != 'N' || direction != 'E' || direction != 'S' || direction != 'W')
    {
    cout << "Which direction? " << endl;
    cin >> direction;
    }
    
    int dirNum = m_myMap.at(m_curRoom)->CheckDirection(direction);

    if (dirNum != -1)
    {
        m_curRoom = dirNum;
        m_myMap.at(m_curRoom)->PrintRoom();
        RandomMonster();
    }
    else
    {

        cout << "You cannot move there!" << endl;
    }
    direction = ' ';
}

void Game::Attack()
{

    if (m_curMonster == NULL)
    {
        cout << "There is nothing to attack in this room" << endl;
        return;
    }

    int attackNum = 0;
    bool defeated = false;

    while (defeated == false)
    {
        while(attackNum > 1 && attackNum < 2){
                    cout << "1. Normal Attack" << endl;
        cout << "2. Special Attack" << endl;
        cin >> attackNum;
        }


        switch (attackNum)
        {
        case 1:
            attackNum = m_myCharacter->Attack();
            m_curMonster->SetHealth(m_curMonster->GetHealth() - attackNum);

            break;

        case 2:

            attackNum = m_myCharacter->SpecialAttack();
            m_curMonster->SetHealth(m_curMonster->GetHealth() - attackNum);

            break;
        }

        int randomNum = rand() % 4 + 1;

        if (m_curMonster->GetHealth() < 1)
        {
            cout << m_curMonster->GetName() << " has been defeated.";
            m_curMonster = NULL;
            defeated = true;
        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Goblin")
        {

            Goblin *tempGoblin = new Goblin();
            attackNum = tempGoblin->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);

            //delete tempGoblin;
            //tempGoblin = NULL;
        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Skeleton")
        {

            Skeleton *tempSkeleton = new Skeleton();
            attackNum = tempSkeleton->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);

            //delete tempSkeleton;
            //tempSkeleton = NULL;
        }
        else if (randomNum == 1 && (m_curMonster->GetName()) == "Baby Dragon")
        {

            BabyDragon *tempDragon = new BabyDragon();
            attackNum = tempDragon->SpecialAttack();
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);
        }
        else
        {
            attackNum = m_curMonster->Attack();
            //attackNum = tempDragon->SpecialAttack;
            m_myCharacter->SetHealth(m_myCharacter->GetHealth() - attackNum);
        }

        if (m_myCharacter->GetHealth() < 1)
        {
            //cout << m_myCharacter->GetName() << " has been defeated." << endl;
            //m_curMonster = NULL;
            defeated = true;
        }
        if (defeated == false)
        {
            cout << m_myCharacter->GetName() << "'s HP:" << m_myCharacter->GetHealth() << endl;
            cout << m_curMonster->GetName() << "'s HP:" << m_curMonster->GetHealth() << endl;
        }

        attackNum = 0;
    }
}

void Game::Stats()
{

    cout << "Name: " << m_myCharacter->GetName() << endl;
    cout << "HP: " << m_myCharacter->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Special: " << m_numSpecial << endl;
}

*/