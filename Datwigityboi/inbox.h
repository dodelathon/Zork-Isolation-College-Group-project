#ifndef INBOX_H
#define INBOX_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QMainWindow>
#include <vector>


class inBox : public QWidget
{
    Q_OBJECT
public:
    explicit inBox(QString nStr = "");
    virtual void setText(QString nStr = "");
    virtual void show();
    virtual void hide();
    virtual ~inBox();

protected:
    QLineEdit inLine;
    QGridLayout mainLayout;
    QGridLayout btnLayout;
    QPushButton okayBtn;
    QPushButton cancelBtn;
    QMainWindow hold;




protected slots:
    virtual void onOkay() = 0;
    virtual void onCancel();
};

#endif // INBOX_H
