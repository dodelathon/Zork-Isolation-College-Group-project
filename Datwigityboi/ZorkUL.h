#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <iostream>
#include <string>
#include "controlpad.h"
using namespace std;

class ZorkUL {
private:
    QMainWindow *window;
	void createRooms();
	void printWelcome();
    void createItems();
    void displayItems();
    ControlPad *controls;

public:
	ZorkUL();
	void play();
};

#endif /*ZORKUL_H_*/
