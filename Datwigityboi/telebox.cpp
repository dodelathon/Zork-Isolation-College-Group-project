#include "telebox.h"
#include "controlpad.h"


TeleBox::TeleBox(QString nStr) : inBox(nStr)
{

}

void TeleBox::onOkay()
{
    ControlPad *caller = ControlPad::getInstance();
    string hold = inLine.text().toStdString();

    Command com("Teleport", hold);
    CPadFunctionality func;
    caller->setLineText(QString::fromStdString(func.processCommand(com, caller->currentRoom) + "\n"));
    this->hide();
}

TeleBox::~TeleBox()
{

}
