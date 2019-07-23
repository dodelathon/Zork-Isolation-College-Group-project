#include "pickbox.h"
#include "controlpad.h"


PickBox::PickBox(QString nStr) : inBox(nStr)
{

}

void PickBox::onOkay()
{
    ControlPad *caller = ControlPad::getInstance();
    string hold = inLine.text().toStdString();

    Command com("take", hold);
    CPadFunctionality func;
    caller->setLineText(QString::fromStdString(func.processCommand(com, caller->currentRoom)));
    this->hide();
    //delete this;
}

PickBox::~PickBox()
{

}
