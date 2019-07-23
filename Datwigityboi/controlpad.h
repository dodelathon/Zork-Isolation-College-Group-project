#ifndef CONTROLPAD_H
#define CONTROLPAD_H


#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextStream>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
#include <iostream>
#include "Command.h"
#include "CommandWords.h"
#include "Room.h"
#include "cpadfunctionality.h"
#include "dropbox.h"
#include "pickbox.h"
#include "telebox.h"
#include "accesspanel.h"

using namespace std;

class ControlPad : public QWidget
{

    Q_OBJECT
    friend class inBox;
    friend class DropBox;
    friend class TeleBox;
    friend class PickBox;
    friend class AccessPanel;
    friend class CPadFunctionality;

    public:
       Player *player;
       ~ControlPad();
       void setLineText(QString hold);
       void setRoom(Room holder);
       string getCurrentRoom();
       static ControlPad* getInstance();
       void setState(int state);
       int getState();



    private:
        ControlPad();
        QPushButton Northbtn, Southbtn, Westbtn, Eastbtn, MapBtn, PickupBtn, invBtn;
        QGridLayout mainLayout, buttonLayout, TBoxLayout;
        QTextEdit displayLine;
        Room *currentRoom;
        CPadFunctionality *functions;
        Command *command;
        string holder;
        QMainWindow hold;
        vector <inBox*> inbox;
        static ControlPad *single;
        enum BOXTYPE
        {
            PICKBOX = 0,
            DROPBOX = 1,
            TELEBOX = 2,
            ACCESSPANEL = 3
        };
        int state;



    private slots:
        void on_North();
        void on_South();
        void on_East();
        void on_West();
        void on_Pickup();
        void on_Map();
        void on_Inventory();

};
#endif // CONTROLPAD_H
