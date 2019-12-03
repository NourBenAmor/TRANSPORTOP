#include "classreservation.h"

#include <QSqlDatabase>
#include <QSql>
#include <QDebug>

classReservation::classReservation()
{
   NumReservation = NombreDePlace= 0;
   prix=0.0;
   trajet=date="";
   adresseEmail="";
}

classReservation::classReservation(int NumReservation,int nombreDePlace,double prix,QString trajet,QString date,QString adresseEmail)
{
    this->NumReservation=NumReservation;
    this->NombreDePlace=nombreDePlace;
    this->prix=prix;
    this->trajet=trajet;
    this->date=date;
    this->adresseEmail=adresseEmail;
}


bool classReservation::ajouterReservation()
{
    QSqlQuery query;
    QString num= QString::number(NumReservation);
    QString  nombre = QString::number(NombreDePlace);
    QString  p = QString::number(prix);
    query.prepare("INSERT INTO Réservation (NOMBREDEPLACE,PRIX,TRAJET,DATEE,ADRESSEEMAIL) "
                        "VALUES (:nombreDePlace,:prix,:trajet,:date,:adresseEmail)");
    //query.bindValue(":numReservation", num);
    query.bindValue(":nombreDePlace",NombreDePlace);
    query.bindValue(":prix", p);
    query.bindValue(":trajet", trajet);
    query.bindValue(":date", date);
    query.bindValue(":adresseEmail", adresseEmail);
    return   query.exec();
}


QSqlQueryModel * classReservation::afficherReservation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM Réservation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numreservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NombreDePlace "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("trajet"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresseEmail"));
    return model;
}

QSqlQueryModel * classReservation::afficherRe(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM Réservation where NUMRESERVATION = '"+id+"'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("numreservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NombreDePlace "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("trajet"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresseEmail"));
    return model;
}

bool classReservation::supprimer(int numReservation)
{
QSqlQuery query;
QString  num = QString::number(numReservation);
query.prepare("Delete from Réservation where NUMRESERVATION = :numReservation ");
query.bindValue(":numReservation", num);
return    query.exec();
}
bool classReservation::modification(int numReservation,int nombreDePlace,double prix,QString trajet,QString date,QString adresseEmail)
{
    QSqlQuery query;
    QString  num = QString::number(numReservation);
    QString  nombre = QString::number(nombreDePlace);
    QString  p = QString::number(prix);
    query.prepare("UPDATE Réservation SET NOMBREDEPLACE =:nombreDePlace,PRIX=:prix,TRAJET=:trajet,DATEE=:date,ADRESSEEMAIL=:adresseEmail where NUMRESERVATION = :numReservation ");
    query.bindValue(":numReservation", num);
    query.bindValue(":nombreDePlace",nombre);
    query.bindValue(":prix", p);
    query.bindValue(":trajet", trajet);
    query.bindValue(":date", date);
    query.bindValue(":adresseEmail", adresseEmail);
    return    query.exec();
}

