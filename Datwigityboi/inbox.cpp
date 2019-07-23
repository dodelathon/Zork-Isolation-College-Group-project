#include "inbox.h"
#include "controlpad.h"

inBox::inBox(QString nStr) : QWidget()
{
    okayBtn.setText("Okay");
    cancelBtn.setText("Cancel");

    btnLayout.addWidget(&okayBtn, 0, 1);
    btnLayout.addWidget(&cancelBtn, 0, 0);

    inLine.setText(nStr);
    mainLayout.addWidget(&inLine, 0, 0);
    mainLayout.addLayout(&btnLayout, 1, 0);
    setLayout(&mainLayout);

    connect(&okayBtn, SIGNAL(released()), this, SLOT(onOkay()));
    connect(&cancelBtn, SIGNAL(released()), this, SLOT(onCancel()));

    hold.setWindowTitle("Input");
    hold.setGeometry(625,250,350,225);
    hold.setCentralWidget(this);
}

void inBox::show()
{
    hold.show();
}

void inBox::hide()
{
    hold.hide();
}

void inBox::onCancel()
{
    hide();
}

void inBox::setText(QString nStr)
{
    inLine.setText(nStr);
}

inBox::~inBox()
{

}
