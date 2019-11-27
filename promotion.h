#ifndef PROMOTION_H
#define PROMOTION_H
#include<QString>
#include<QSqlQuery>
#include<QVariant>
#include <QSqlQueryModel>



class Promotion
{
public:
    Promotion();
    Promotion(int,QString,QString,QString,QString);
    void setid(int);
    void setnom(QString);
    void setdatefin(QString);
    void setdatedebut(QString);
    void setcontenu(QString);
    int getid();
    QString getnom();
    QString getdatefin();
    QString getdatedebut();
    QString getcontenu();
    bool ajouterpromotion();
    bool supprimerpromotion(QString);
    bool modifierpromotion(QString,QString,QString,QString,QString);
    QSqlQueryModel * consulter();
    QSqlQueryModel * consulter2(QString);
    static QSqlQueryModel *consultertrie();



private:
    int id;
    QString nom;
    QString date_debut;
    QString date_fin;
    QString contenu;

};

#endif // PROMOTION_H
