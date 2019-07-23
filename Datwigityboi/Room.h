#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <QString>
#include <QTextEdit>
//#include <list>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    static vector <Room*> rooms;
    string description;
    vector <Item> itemsInRoom;
    static void addRoom(Room *temp);
    map<string, Room*> exits;
    string discoverText;


public:
    int numberOfItems();
    string exitString();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    void setDiscText(string text);
    string getDiscText();
    string displayItem();
    Item isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    static Room *getRoom(string roomLetter);
    friend string& operator<<(string &tempo, Room &temp);
    friend ostream& operator<<(ostream &tempo, Room &temp);

};
#endif
