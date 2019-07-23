#ifndef CPADFUNCTIONALITY_H
#define CPADFUNCTIONALITY_H


#include <iostream>
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"
#include "Parser.h"
#include "player.h"

class CPadFunctionality
{
    private:
        Parser parser;
        string teleport(Command command, Room &currentRoom);
        string goRoom(Command command, Room &currentRoom);
        string printHelp();

    public:
        CPadFunctionality();
        string processCommand(Command command, Room *currentRoom);
};

#endif // CPADFUNCTIONALITY_H
