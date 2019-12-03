#ifndef CLASSRESERVATION_H
#define CLASSRESERVATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class classReservation
{
private:
    int NumReservation;
    int NombreDePlace;
    double prix;
    QString trajet;
    QString date;
    QString adresseEmail;
public:
    classReservation();
    classReservation(int,int,double,QString,QString,QString);
    int getNumReservation() {return NumReservation;}
    int getNombreDePlace() {return NombreDePlace;}
    double getPrix() {return prix;}
    QString getTrajet() {return trajet;}
    QString getDate() {return date;}
    QSqlQueryModel * afficherReservation();
    QSqlQueryModel * afficherRe(QString id);
    bool supprimer(int);
    bool modification(int,int,double,QString,QString,QString);
    bool ajouterReservation();
};

#endif // CLASSRESERVATION_H
