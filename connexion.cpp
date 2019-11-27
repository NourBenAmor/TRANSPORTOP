#include "connexion.h"
#include <exception>
#include <QDebug>
#include <QSqlError>
connexion::connexion()
{

}

bool connexion::createconnection()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projj");
db.setUserName("ouss");//inserer nom de l'utilisateur
db.setPassword("123");//inserer mot de passe de cet utilisateur

if (db.open())
return test=true;
else{
            qDebug()<<db.lastError().text();
return false;}
}







