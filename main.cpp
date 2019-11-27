#include "mainwindow.h"
#include"connexion.h"
#include<QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    if(c.createconnection())
    {
        w.show();
    }
    return a.exec();
}
