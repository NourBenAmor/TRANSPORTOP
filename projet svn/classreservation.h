#ifndef CLASSRESERVATION_H
#define CLASSRESERVATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>

class classReservation
{
private:
    int NumReservation;
    int NombreDePlace;
    double prix;
    QString trajetD,trajetA;
    QString dateD,dateA;
    QString adresseEmail;
public:
    classReservation();
    classReservation(int,double,QString,QString,QString,QString,QString);
    int getNumReservation() {return NumReservation;}
    int getNombreDePlace() {return NombreDePlace;}
    bool existeee(int);
    double getPrix() {return prix;}
    QString getTrajetD() {return trajetD;}
    QString getDateD() {return dateD;}
    QString getTrajetA() {return trajetA;}
    QString getDateA() {return dateA;}
    QSqlQueryModel * afficherReservation();
    QSqlQueryModel * afficherRe(QString id);
    bool supprimer(int);
    bool modification(int,int,double,QString,QString,QString,QString,QString);
    bool ajouterReservation();
};

#endif // CLASSRESERVATION_H
