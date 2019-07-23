#ifndef PICKBOX_H
#define PICKBOX_H

#include "inbox.h"

class PickBox : public inBox
{
public:
    PickBox(QString nStr = "");
    virtual ~PickBox();

private slots:
    virtual void onOkay();
};

#endif // PICKBOX_H
