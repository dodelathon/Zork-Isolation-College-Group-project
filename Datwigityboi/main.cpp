#include <QApplication>
#include <iostream>
using namespace std;
#include "ZorkUL.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    ZorkUL temp;
    temp.play();

    return a.exec();
}
