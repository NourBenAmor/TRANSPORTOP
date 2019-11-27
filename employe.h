#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{public:
    Employe();
    Employe(int,QString,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_telephone();
    QString get_cin();

    int get_id();

        bool ajouter();
        bool update();
        QSqlQueryModel * afficher();
        QSqlQueryModel * afficher2(QString);

        bool supprimer(int);
        void chercher();
        void search();

private:
    QString nom,prenom,adresse,cin,telephone;
    int id;
};

#endif // EMPLOYE_H
