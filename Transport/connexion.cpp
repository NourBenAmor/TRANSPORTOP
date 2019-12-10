#include "connexion.h"
#include <QSqlError>
connexion::connexion(){
                      }
bool connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("Source_Projet2A.");
                           db.setUserName("ahmed");//inserer nom de l'utilisateur
                           db.setPassword("ahmed22");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void connexion::fermerConnexion()
{db.close();}
