#include "mainwindow.h"
#include"adressbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdressBook* adr = new AdressBook();
    adr->show();
    return a.exec();
}
