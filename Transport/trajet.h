#ifndef TRAJET_H
#define TRAJET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Trajet
{public:
    Trajet();
    Trajet(int,QString,QString,QString,QString,QString);
    QString get_dated();
    QString get_datea();
    QString get_stationd();
    QString get_stationa();
    int get_num();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *afficher2();
    QSqlQueryModel *afficher3(QString);
bool supprimer(int);
bool modifier(int ,QString,QString ,QString ,QString ,QString );

private:
    QString dated,datea,stationd,stationa,IDBus;
    int num;
};

#endif // ETUDIANT_H
