#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;
    bool test=c.ouvrirConnexion();
    if(test)
    {
        MainWindow w;
        w.show();
        return a.exec();

    }
return 0;
}
