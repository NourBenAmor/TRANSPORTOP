#ifndef CLASSEMPLOYEE_H
#define CLASSEMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class classEmployee
{
public:
    classEmployee();
    classEmployee(int,QString,QString,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_telephone();
    QString get_cin();
    QString get_poste();

    int get_id();
    int verifierStatut(QString,QString);
    int verifierCompte(QString,QString);

        bool ajouter();
        bool update();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher2(QString);

        bool supprimer(int);
        void chercher();
        void search();

private:
    QString nom,prenom,adresse,cin,telephone,poste;
    int id;
};

#endif // CLASSEMPLOYEE_H
