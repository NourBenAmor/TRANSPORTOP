#ifndef PROMOTION_H
#define PROMOTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Promotion
{
public:
    Promotion();
    Promotion(QString,QString,QString,QString,QString);
    void setid(QString);
    void setnom(QString);
    void setdatedebut(QString);
    void setdatefin(QString);
    void setcontenu(QString);
    QString getid();
    QString getnom();
    QString getdatedebut();
    QString getdatefin();
    QString getcontenu();
    bool ajouter_Promotion();
    bool modifier_Promotion();
    bool supprimer_Promotion();
    QSqlQueryModel * afficher_Promotion();
    QSqlQueryModel * afficher_list();
    void chercher();
    bool existe(QString);
    QSqlQueryModel * recherche(QString valeur, int etat);

private:
    QString id,nom,datedebut,datefin,contenu;


};

#endif // PROMOTION_H
