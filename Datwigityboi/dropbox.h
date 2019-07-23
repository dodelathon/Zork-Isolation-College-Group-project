#ifndef DROPBOX_H
#define DROPBOX_H

#include "inbox.h"

class DropBox : public inBox
{
public:
    DropBox(QString nStr = "");
    virtual ~DropBox();

protected slots:
    virtual void onOkay();

};

#endif // DROPBOX_H
