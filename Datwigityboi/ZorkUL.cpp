#include <iostream>

using namespace std;
#include "ZorkUL.h"
//#include "controlpad.h"

ZorkUL::ZorkUL()
{
    controls = ControlPad::getInstance();
    window = new QMainWindow();
	createRooms();
}

void ZorkUL::createRooms()
{
    new Room("a");
        Room::getRoom("a")->addItem(new Item("Control Panel Wires", 1, 11));
    new Room("b");
        Room::getRoom("b")->addItem(new Item("xx", 3, 33));
        Room::getRoom("b")->addItem(new Item("yy", 4, 44));

    new Room("c");
    new Room("d");
    new Room("e");
    new Room("f");
    new Room("g");
    new Room("h");
    new Room("i");
    new Room("j");

    Room::getRoom("a")->setDiscText("");
    Room::getRoom("b")->setDiscText("This room is a bit of a crossroad.You've completed your first obstacle.But there is surely more to come");
    Room::getRoom("c")->setDiscText("This room seems like a dead end.There's another cryo-pod here, it's labelled \"POD 42, Captain Douglas Adams\".Guess the captain didn't wake up, it's up to me to get this ship back online");
    Room::getRoom("d")->setDiscText("Another hallway.There's a door to the West");
    Room::getRoom("e")->setDiscText("There is what appears to be an old service robot in the corner.You recognise it as C|-|R1$, who maintained the code on all the integrated systems aboard this level.As you approach it stutters to life.\"grEetiNgs job equals janiTor, ElectRicity is\".It begins to shudder and click for a few moments.\"vmdofoerds faili-----fgfdsodfgdfskgdfghtwfdsh\".The robot's head droops as it shuts down.What could it have been trying say? It seemed important");
    Room::getRoom("f")->setDiscText("That door up ahead looks locked.It requires an access code");
    Room::getRoom("g")->setDiscText("There's a strange atmosphere to this room.The air feels colder, with a certain electricity to it");
    Room::getRoom("h")->setDiscText("You now rememeber that you are close to the bridge.Though a somehow operational security bot blocks your path!.You recognise it as R4F43|_, the stoic and dauntless protector of this level.His optical sensor seems to be damaged and it's apparent he can't tell exactly who you are.He calls out to you \"YOU AREN'T MEANT TO BE AWAKE, STATE YOUR POD NUMBER OR FACE THE CONSEQUENCES\"");
    Room::getRoom("i")->setDiscText("This is it!.The door to the bridge!.Looks like that terminal controls the door");
    Room::getRoom("j")->setDiscText("There is a large desk central to the bridge.It has numerous buttons all over the dashboard.You can't quite figure out what they all mean.But from passing knowlege you know the following:.-One will self destruct the ship.-One will jetison the cryo-pods.-One will return power to the ship.You must choose wisely which to press.RED, BLUE, or GREEN?");


//             (N, E, S, W)
    Room::getRoom("a")->setExits(Room::getRoom("b"),NULL, NULL, NULL);
    Room::getRoom("b")->setExits(Room::getRoom("d"), Room::getRoom("f"), Room::getRoom("a"), Room::getRoom("c"));
    Room::getRoom("c")->setExits(NULL, Room::getRoom("b"), NULL, NULL);
    Room::getRoom("d")->setExits(NULL, NULL, Room::getRoom("b"), Room::getRoom("e"));
    Room::getRoom("e")->setExits(NULL, Room::getRoom("d"), NULL, NULL);
    Room::getRoom("f")->setExits(Room::getRoom("g"), NULL, NULL, Room::getRoom("b"));
    Room::getRoom("g")->setExits(Room::getRoom("h"), NULL, Room::getRoom("f"), NULL);
    Room::getRoom("h")->setExits(NULL, NULL, Room::getRoom("g"), Room::getRoom("i"));
    Room::getRoom("i")->setExits(NULL, Room::getRoom("h"), NULL, Room::getRoom("j"));
    Room::getRoom("j")->setExits(NULL, Room::getRoom("i"), NULL, NULL);
    controls->setRoom(*Room::getRoom("a"));
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play()
{
    window->setGeometry(625,250,700,550);
    window->setCentralWidget(controls);
    window->show();
    printWelcome();
}

void ZorkUL::printWelcome()
{
    controls->setLineText("Your vision slowly begins to return to you");
    controls->setLineText("As you can feel the cold around you dissipate");
    controls->setLineText("The hatch of your cryo-pod, pod 40, lurches open");
    controls->setLineText("Revealing a darkened room");
    controls->setLineText("You step out to see pod 41 next to you sparking");
    controls->setLineText("As if malfunctioning");
    controls->setLineText("It seems as though power aboard this ship has failed");
    controls->setLineText("You realise you must find the bridge to restore power.");
    controls->setLineText("");
    controls->setLineText("*info for help*");
    controls->setLineText("");
    controls->setLineText(QString::fromStdString(controls->getCurrentRoom()) + "\n");
}

