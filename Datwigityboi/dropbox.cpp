#include "dropbox.h"
#include "controlpad.h"


DropBox::DropBox(QString nStr) : inBox(nStr)
{

}

void DropBox::onOkay()
{
    ControlPad *caller = ControlPad::getInstance();
    caller->holder = inLine.text().toStdString();
    hide();
}

DropBox::~DropBox()
{

}
