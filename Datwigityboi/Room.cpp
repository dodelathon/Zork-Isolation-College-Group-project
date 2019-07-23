#include "Room.h"
#include "Command.h"

std::vector<Room*> Room::rooms;

Room::Room(string description)
{
	this->description = description;
    addRoom(this);
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription()
{
	return description;
}

string Room::exitString()
{
    string returnString = "\nExits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
    {
        return NULL;
    }
    // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::setDiscText(string text)
{
    this->discoverText = text;
}

string Room::getDiscText()
{
    return this->discoverText;
}

void Room::addItem(Item *inItem)
{
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem()
{
    string tempString = "Items in room = ";
    unsigned int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1)
    {
        tempString = "No items in here!";
    }
    else if (itemsInRoom.size() > 0)
    {
        unsigned int x = (0);
        for (unsigned int n = sizeItems; n > 0; n--)
        {
            if(itemsInRoom[x].getShortDescription().compare("MARKED") == 0)
            {
                itemsInRoom.erase(itemsInRoom.begin() + x);
                x++;
            }
            else
            {
                tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
                x++;
            }
        }
        if(itemsInRoom.size() < 1)
        {
            tempString = "No items in here!";
        }
    }
    return tempString;
}

int Room::numberOfItems()
{
    return itemsInRoom.size();
}

Item Room::isItemInRoom(string inString)
{
    Item hold("");
    unsigned int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1)
    {
        return hold;
    }
    else if (itemsInRoom.size() > 0)
    {
        vector<Item>::iterator n;
        bool found = false;
        for (n = itemsInRoom.begin(); n != itemsInRoom.end() && found == false; ++n)
        {
            // compare inString with short description
            int tempFlag = inString.compare( (*n).getShortDescription());
            if (tempFlag == 0)
            {
                found = true;
                Item hold = *n;
                (*n).setValue(NULL);
                (*n).setWeight(NULL);
                (*n) = "MARKED";
                return hold;
            }
        }
    }
    return hold;
}

void Room::addRoom(Room *temp)
{
    rooms.push_back(temp);
}

Room* Room::getRoom(string roomLetter)
{
    for(unsigned int i = 0; i < rooms.size(); i++)
    {
        if(rooms.at(i)->shortDescription() == roomLetter)
        {
            return rooms.at(i);
        }
    }
    return NULL;
}

string& operator<<(string &tempo, Room &temp)
{
    tempo += "Room = " + temp.description + ".\n" + temp.displayItem() + temp.exitString() + "\n";
    return tempo;
}

ostream& operator<<(ostream &tempo, Room &temp)
{
        tempo << "Room = " << temp.description << ".\n" << temp.displayItem() << temp.exitString() << endl;
        return tempo;
}


