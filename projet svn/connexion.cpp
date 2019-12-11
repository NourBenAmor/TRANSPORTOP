#include "connexion.h"
#include <exception>
Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
    db.setUserName("meriem");
    db.setPassword("esprit19");
if (db.open())
    test=true;
else
    throw QString ("Erreur Paramétres"+test);
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
