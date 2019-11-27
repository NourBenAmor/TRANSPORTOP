#include "connexion.h"
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("181JFT1965");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
else
    throw QString ("Erreur Paramétres");
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
