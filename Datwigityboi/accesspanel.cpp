#include "accesspanel.h"
#include "controlpad.h"
#include<QKeyEvent>

AccessPanel::AccessPanel(QString nStr) : inBox(nStr)
{

}

void AccessPanel::onOkay()
{
    ControlPad *caller = ControlPad::getInstance();
    string hold = inLine.text().toStdString();
    if(caller->getState() == 1)
    {
        if(hold.compare("ENTER") == 0)
        {
            caller->setState(2);
            caller->setLineText("The door beeps and opens as you input the correct code");
            caller->setLineText("");
        }
        else
        {
            caller->setLineText("That seems to have been an incorrect code");
        }
    }
    else if(caller->getState() == 2)
    {
        if(hold.compare("42") == 0)
        {
            caller->setState(3);
            caller->setLineText("\"Ah, Captain, I am so sorry! I was not briefed on this early awakening.\"");
            caller->setLineText("R4F43|_ stands aside and allows you to pass through");
            caller->setLineText("");
        }
        else
        {
            caller->setLineText("INTRUDER ALERT! INTRUDER ALERT! INTRUDER ALERT!");
            caller->setLineText("");
            caller->setLineText("G  A   M   E");
            caller->setLineText("O  V   E   R");
            caller->setLineText("");
            caller->currentRoom->setExits(NULL,NULL,NULL,NULL);
        }
    }
    else if(caller->getState() == 3)
    {
        if(hold.compare("RED") == 0)
        {
            caller->setLineText("The ship begins to shake and grumble");
            caller->setLineText("You think why the hell did you press the red one");
            caller->setLineText("Everyone knows the red one is bad");
            caller->setLineText("Suddenly, the lights begin to flicker");
            caller->setLineText("And you see the ship begin to shift from backup energy to the main generators");
            caller->setLineText("You have saved the ship!");
            caller->setLineText("But who thought it was a good idea to make this the red button?");
            caller->setLineText("");
            caller->setLineText("G  A   M   E");
            caller->setLineText("O  V   E   R");
            caller->currentRoom->setExits(NULL,NULL,NULL,NULL);
        }
        else if(hold.compare("BLUE") == 0)
        {
            caller->setLineText("You think blue for electricity makes some sense");
            caller->setLineText("You have watched cartoons before and it's always blue or yellow");
            caller->setLineText("Suddenly you hear sounds like cannon fire");
            caller->setLineText("As you see pod 42 float right past the bridge window");
            caller->setLineText("You realise you have doomed yourself and your crew, one person cannot handle a whole ship");
            caller->setLineText("You guess blue was for ice all along...");
            caller->setLineText("");
            caller->setLineText("G  A   M   E");
            caller->setLineText("O  V   E   R");
            caller->currentRoom->setExits(NULL,NULL,NULL,NULL);
        }
        else if(hold.compare("GREEN") == 0)
        {
            caller->setLineText("This one was obvious!");
            caller->setLineText("Green for good, green for go, for grass, for serenity");
            caller->setLineText("This serenity is swiftly and abruptly ended by an explosion");
            caller->setLineText("Removing your legs from your body");
            caller->setLineText("You have doomed this vessel and all aboard it");
            caller->setLineText("Who decided green would be a good colour for a button that kills us all");
            caller->setLineText("Everything fades to black");
            caller->setLineText("");
            caller->setLineText("G  A   M   E");
            caller->setLineText("O  V   E   R");
            caller->currentRoom->setExits(NULL,NULL,NULL,NULL);
            //EXIT IF KEY IS PRESSED
        }
    }
    this->hide();
}

AccessPanel::~AccessPanel()
{

}
