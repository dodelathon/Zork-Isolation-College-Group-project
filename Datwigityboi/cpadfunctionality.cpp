#include "cpadfunctionality.h"
#include"controlpad.h"

CPadFunctionality::CPadFunctionality()
{

}

string CPadFunctionality::processCommand(Command command, Room *currentRoom)
{
    ControlPad *control = ControlPad::getInstance();
    string holder = "";
    if (command.isUnknown())
    {
        return "invalid input";
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
    {
        holder = printHelp();
    }

    else if (commandWord.compare("go") == 0)
    {
        holder = goRoom(command, *currentRoom);
    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            holder = "incomplete input";
        }
        else if (command.hasSecondWord())
        {
           Item possibleItem = currentRoom->isItemInRoom(command.getSecondWord());
           if (possibleItem.getShortDescription() == "MARKED" || possibleItem.getShortDescription() == "")
           {
               holder += "item is not in room! \n";
           }
           else
           {
               *control->player + possibleItem;
               holder += "Item: " + possibleItem.getShortDescription() + " has been added to you inventory\n\n";
               if(possibleItem.getShortDescription().compare("Control Panel Wires") == 0){
                   control->setState(1);
                   control->setLineText("You manage to pull some wires from the cryo-pod control panel");
                   control->setLineText("You use these to short-circuit the door controls, clearing a path to the next room");
               }
               holder << *currentRoom;
           }
         }
        return holder;

     }

    else if (commandWord.compare("put") == 0)
    {

    }
    else if(commandWord.compare("Teleport") == 0)
    {
        if(command.hasSecondWord())
        {
            holder = teleport(command, *currentRoom);
        }
        else
        {
            cout << "No room selected"<< endl;
        }
        return holder;

    }
    return holder;
}

string CPadFunctionality::goRoom(Command command, Room &currentRoom)
{
    ControlPad *control = ControlPad::getInstance();
    string holder = "";
    if (!command.hasSecondWord())
    {
        holder = "incomplete input\n";;
        return holder;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    //cout << currentRoom.exitString() << endl;
    Room* nextRoom = currentRoom.nextRoom(direction);

    if (nextRoom == NULL)
    {
        holder =  "There is no room in that direction\n";
    }
    else
    {
        if(nextRoom->shortDescription().compare("b") == 0)
        {
            if(control->getState() == 0)
            {
                control->setLineText("The door is locked. Maybe I could find some way to open it");
                return holder;
            }
        }
        else if((nextRoom->shortDescription().compare("g") == 0))
        {
            if(control->getState() == 1)
            {
                control->setLineText("The door requires an access code. Perhaps I could find it somewhere");
                control->inbox.at(control->ACCESSPANEL)->setText("Door Access Panel");
                control->inbox.at(control->ACCESSPANEL)->show();
                return holder;
            }
        }
        else if((nextRoom->shortDescription().compare("i") == 0))
        {
            if(control->getState() == 2)
            {
                control->inbox.at(control->ACCESSPANEL)->setText("State Your Pod Number");
                control->inbox.at(control->ACCESSPANEL)->show();
                return holder;
            }
        }
        ControlPad *control = ControlPad::getInstance();
        currentRoom = *nextRoom;

        string text = currentRoom.getDiscText();
        string split = ".";
        size_t pos = 0;
        string token;
        while ((pos = text.find(split)) != std::string::npos) {
            token = text.substr(0, pos);
            control->setLineText(QString::fromStdString(token));
            text.erase(0, pos + split.length());
        }
        control->setLineText(QString::fromStdString(text));
        holder << currentRoom;
        if(currentRoom.shortDescription().compare("j") == 0)
        {
            control->inbox.at(control->ACCESSPANEL)->setText("/RED/BLUE/GREEN/?");
            control->inbox.at(control->ACCESSPANEL)->show();
        }
    }
    return holder;
}

string CPadFunctionality::printHelp()
{
    string holder = "";
    holder += "valid inputs are; \n";
    holder += parser.showCommands();
    return holder;

}

string CPadFunctionality::teleport(Command command, Room &currentRoom)
{
    string holder = "";
    if(command.getSecondWord() == ("a"))
    {
        currentRoom = *Room::getRoom("a");
        holder += "Teleported to room \"a\"\n";
    }
    else if(command.getSecondWord() == ("b"))
    {
        currentRoom = *Room::getRoom("b");
        holder += "Teleported to room \"b\"\n";
    }
    else if(command.getSecondWord() == ("c"))
    {
        currentRoom = *Room::getRoom("c");
        holder += "Teleported to room \"c\"\n";
    }
    else if(command.getSecondWord() == ("d"))
    {
        currentRoom = *Room::getRoom("d");
        holder += "Teleported to room \"d\"\n";
    }
    else if(command.getSecondWord() == ("e"))
    {
        currentRoom = *Room::getRoom("e");
        holder += "Teleported to room \"e\"\n";
    }
    else if(command.getSecondWord() == ("f"))
    {
        currentRoom = *Room::getRoom("f");
        holder += "Teleported to room \"f\"\n";
    }
    else if(command.getSecondWord() == ("g"))
    {
        currentRoom = *Room::getRoom("g");
        holder += "Teleported to room \"g\"\n";
    }
    else if(command.getSecondWord() == ("h"))
    {
        currentRoom = *Room::getRoom("h");
        holder += "Teleported to room \"h\"\n";
    }
    else if(command.getSecondWord() == ("i"))
    {
        currentRoom = *Room::getRoom("i");
        holder += "Teleported to room \"i\"\n";
    }
    else if(command.getSecondWord() == ("j"))
    {
        currentRoom = *Room::getRoom("j");
        holder += "Teleported to room \"j\"\n";
    }
    else
    {
        holder += "Room does not exist!\n";
    }
    return holder;
}

