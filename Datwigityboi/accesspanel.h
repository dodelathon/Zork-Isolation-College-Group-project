#ifndef ACCESSPANEL_H
#define ACCESSPANEL_H

#include "inbox.h"

class AccessPanel : public inBox
{
public:
    AccessPanel(QString nStr = "");
    virtual ~AccessPanel();

private slots:
    virtual void onOkay();
};

#endif // ACCESSPANEL_H
