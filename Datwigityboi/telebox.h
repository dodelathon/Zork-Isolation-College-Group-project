#ifndef TELEBOX_H
#define TELEBOX_H

#include <QWidget>
#include "inbox.h"

class TeleBox : public inBox
{
    Q_OBJECT
public:
    explicit TeleBox(QString nStr = "");
    virtual ~TeleBox();


private slots:
    virtual void onOkay();
};

#endif // TELEBOX_H
