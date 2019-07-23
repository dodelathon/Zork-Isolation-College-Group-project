#include "controlpad.h"
#include "player.h"

ControlPad* ControlPad::single;

ControlPad::ControlPad()
{
    player = new Player();

    state = 0;
    currentRoom = new Room("");
    command = new Command();
    functions = new CPadFunctionality();
    inbox.push_back(new PickBox());
    inbox.push_back(new DropBox());
    inbox.push_back(new TeleBox());
    inbox.push_back(new AccessPanel());

    Northbtn.setText("North");
    Southbtn.setText("South");
    Eastbtn.setText("East");
    Westbtn.setText("West");
    MapBtn.setText("Map");
    PickupBtn.setText("Pickup item");
    invBtn.setText("Show Inventory");

    displayLine.setReadOnly(true);

    TBoxLayout.addWidget(&displayLine, 0, 1);

    buttonLayout.addWidget(&MapBtn, 0, 2, 1, 1);
    buttonLayout.addWidget(&PickupBtn, 0, 0, 1, 1);
    buttonLayout.addWidget(&Northbtn, 1, 1, 1, 1);
    buttonLayout.addWidget(&Southbtn, 2, 1, 1, 1);
    buttonLayout.addWidget(&Eastbtn, 2, 2, 1, 1);
    buttonLayout.addWidget(&Westbtn, 2, 0, 1, 1);
    buttonLayout.addWidget(&invBtn, 0, 1, 1, 1);

    mainLayout.addLayout(&TBoxLayout, 0, 1, Qt::AlignCenter);
    mainLayout.addLayout(&buttonLayout, 1, 1, Qt::AlignBottom);
    setLayout(&mainLayout);

    connect(&Northbtn, SIGNAL(released()), this, SLOT(on_North()));
    connect(&Southbtn, SIGNAL(released()), this, SLOT(on_South()));
    connect(&Eastbtn, SIGNAL(released()), this, SLOT(on_East()));
    connect(&Westbtn, SIGNAL(released()), this, SLOT(on_West()));
    connect(&MapBtn, SIGNAL(released()), this, SLOT(on_Map()));
    connect(&PickupBtn, SIGNAL(released()), this, SLOT(on_Pickup()));
    connect(&invBtn, SIGNAL(released()), this, SLOT(on_Inventory()));
}

void ControlPad::on_North()
{
       command->setCommandWord("go");
       command->setSecondWord("north");
       holder = functions->processCommand(*command, currentRoom);
       setLineText(QString::fromStdString(holder));
}

void ControlPad::on_South()
{
    command->setCommandWord("go");
    command->setSecondWord("south");
    holder = functions->processCommand(*command, currentRoom);
    setLineText(QString::fromStdString(holder));
}

void ControlPad::on_East()
{
    command->setCommandWord("go");
    command->setSecondWord("east");
    holder = functions->processCommand(*command, currentRoom);
    setLineText(QString::fromStdString(holder));
}

void ControlPad::on_West()
{
    command->setCommandWord("go");
    command->setSecondWord("west");
    holder = functions->processCommand(*command, currentRoom);
    setLineText(QString::fromStdString(holder));
}

void ControlPad::on_Map()
{
    setLineText(" [j] --- [i] --- [h]");
    setLineText("                     | ");
    setLineText("[e] --- [d]     [g]");
    setLineText("           |        | ");
    setLineText("[c] --- [b] --- [f]");
    setLineText("           |         ");
    setLineText("           |         ");
    setLineText("          [a]        ");

}

void ControlPad::on_Inventory()
{
    setLineText("\t Inventory:");

    for(unsigned int i=0; i<player->getInventory().size();i++)
    {
        setLineText(QString::fromStdString("\t       " + player->getInventory().at(i).getShortDescription()));
    }
    setLineText("******************************");
}

void ControlPad::on_Pickup()
{
    inbox.at(PICKBOX)->show();
    inbox.at(PICKBOX)->setText("Picking Up Item");
}

void ControlPad::setState(int state)
{
    this->state = state;
}

int ControlPad::getState()
{
    return this->state;
}

void ControlPad::setLineText(QString hold)
{
    //cout << hold.toLocal8Bit().constData() << endl;
    displayLine.append(hold);
}

void ControlPad::setRoom(Room holder)
{
    *currentRoom = holder;
}

string ControlPad::getCurrentRoom()
{
    holder = "";
    holder << *currentRoom;
    return holder;
}

ControlPad* ControlPad::getInstance()
{
    if(ControlPad::single == NULL)
    {
        single = new ControlPad();
    }
    return single;
}

ControlPad::~ControlPad()
{
    delete this;
}
