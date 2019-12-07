#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>
#include <connexion.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Connexion c;
    try {
       bool t=c.ouvrirConnexion();
        w.show();
        qDebug()<<t;

    } catch (QString s) {
        qDebug()<<s;

    }
    return a.exec();
}
