#ifndef CLASSBUS_H
#define CLASSBUS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class classBus
{
public:
    classBus();
   classBus(int,QString,QString,QString,int,QString,QString);
   QString get_matricule();
   QString get_marque();
   QString get_etat();
   QString get_chauffeur();
   QString get_disponibilite();
   int get_id();
   int get_capacite();
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int);
private:
   QString matricule,marque,etat,chauffeur,disponibilite;
   int id,capacite;
};

#endif // CLASSBUS_H
