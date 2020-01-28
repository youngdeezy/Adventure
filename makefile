CXX = g++
CXXFLAGS = -Wall

proj4: BabyDragon.o Character.o Entity.o Game.o Goblin.o Monster.o Paladin.o Rogue.o Room.o Skeleton.o Wizard.o proj4.cpp
        $(CXX) $(CXXFLAGS) BabyDragon.o Character.o Entity.o Game.o Goblin.o Monster.o Paladin.o Rogue.o Room.o Skeleton.o Wizard.o proj4.cpp -o proj4

BabyDragon.o: BabyDragon.h BabyDragon.cpp Monster.o
        $(CXX) $(CXXFLAGS) -c BabyDragon.cpp

Character.o: Character.h Character.cpp Entity.o
        $(CXX) $(CXXFLAGS) -c Character.cpp

Entity.o: Entity.h Entity.cpp 
        $(CXX) $(CXXFLAGS) -c Entity.cpp

Game.o: Game.h Game.cpp BabyDragon.o Character.o Entity.o Goblin.o Monster.o Paladin.o Rogue.o Room.o Skeleton.o Wizard.o 
        $(CXX) $(CXXFLAGS) -c Game.cpp

Goblin.o: Goblin.h Goblin.cpp Monster.o
        $(CXX) $(CXXFLAGS) -c Goblin.cpp

Monster.o: Monster.h Monster.cpp Entity.o
        $(CXX) $(CXXFLAGS) -c Monster.cpp

Paladin.o: Paladin.h Paladin.cpp Character.o
        $(CXX) $(CXXFLAGS) -c Paladin.cpp

Rogue.o: Rogue.h Rogue.cpp Character.o
        $(CXX) $(CXXFLAGS) -c Rogue.cpp

Room.o: Room.h Room.cpp
        $(CXX) $(CXXFLAGS) -c Room.cpp

Skeleton.o: Skeleton.h Skeleton.cpp Monster.o
        $(CXX) $(CXXFLAGS) -c Skeleton.cpp

Wizard.o: Wizard.h Wizard.cpp Character.o
        $(CXX) $(CXXFLAGS) -c Wizard.cpp

run:
        ./proj4

val1:
        valgrind ./proj4

clean:
        rm *~








