#include "classreservation.h"

#include <QSqlDatabase>
#include <QSql>
#include <QDebug>

classReservation::classReservation()
{
   NumReservation = NombreDePlace= 0;
   prix=0.0;
   trajetD=dateD=trajetA=dateA="";
   adresseEmail="";
}

classReservation::classReservation(int nombreDePlace,double prix,QString trajetD,QString dateD,QString trajetA,QString dateA,QString adresseEmail)
{
    //this->NumReservation=NumReservation;
    this->NombreDePlace=nombreDePlace;
    this->prix=prix;
    this->trajetD=trajetD;
    this->dateD=dateD;
    this->trajetA=trajetA;
    this->dateA=dateA;
    this->adresseEmail=adresseEmail;
}


bool classReservation::ajouterReservation()
{
    QSqlQuery query;
    QString num= QString::number(NumReservation);
    QString  nombre = QString::number(NombreDePlace);
    QString  p = QString::number(prix);
    query.prepare("INSERT INTO Réservation (NOMBREDEPLACE,PRIX,TRAJETD,DATED,ADRESSEEMAIL,TRAJETA,DATEA) "
                        "VALUES (:nombreDePlace,:prix,:trajetD,:dateD,:adresseEmail,:trajetA,:dateA)");
    //query.bindValue(":numReservation", num);
    query.bindValue(":nombreDePlace",NombreDePlace);
    query.bindValue(":prix", p);
    query.bindValue(":trajetD", trajetD);
    query.bindValue(":dateD", dateD);
    query.bindValue(":trajetD", trajetA);
    query.bindValue(":dateD", dateA);
    query.bindValue(":adresseEmail", adresseEmail);
    return   query.exec();
}


QSqlQueryModel * classReservation::afficherReservation()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM Réservation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Réservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre De Place"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TrajetD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateD"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("TrajetA"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("DateA"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse Email"));
    return model;
}

QSqlQueryModel * classReservation::afficherRe(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM Réservation where NUMRESERVATION = '"+id+"'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Réservation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre De Place "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TrajetD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateD"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("TrajetA"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("DateA"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse Email"));
    return model;
}

bool classReservation::supprimer(int numReservation)
{
            existeee(numReservation);
    QSqlQuery query;
    QString  num = QString::number(numReservation);
    query.prepare("Delete from Réservation where NUMRESERVATION = :numReservation ");
    query.bindValue(":numReservation", num);
    return    query.exec();

}

bool classReservation::existeee(int numReservation)
{
    QSqlQuery query;
    QString n;
    QString  num = QString::number(numReservation);
            query.exec("SELECT NUMRESERVATION from Réservation");
            while (query.next())
            {
                n=query.value("NUMRESERVATION").toString();
                if (n==num)
                {
                    qDebug()<<"mawjouda mech f le5er";
                    return true;
                }
            }
    qDebug()<<"mech mawjouda jemla";
    return false;
}

bool classReservation::modification(int numReservation,int nombreDePlace,double prix,QString trajetD,QString dateD,QString trajetA,QString dateA,QString adresseEmail)
{
    QSqlQuery query;
    QString  num = QString::number(numReservation);
    QString  nombre = QString::number(nombreDePlace);
    QString  p = QString::number(prix);
    query.prepare("UPDATE Réservation SET NOMBREDEPLACE =:nombreDePlace,PRIX=:prix,TRAJETD=:trajetD,DATED=:dateD,TRAJETA=:trajetA,DATEA=:dateA,ADRESSEEMAIL=:adresseEmail where NUMRESERVATION = :numReservation ");
    query.bindValue(":numReservation", num);
    query.bindValue(":nombreDePlace",nombre);
    query.bindValue(":prix", p);
    query.bindValue(":trajetD", trajetD);
    query.bindValue(":dateD", dateD);
    query.bindValue(":trajetA", trajetA);
    query.bindValue(":dateA", dateA);
    query.bindValue(":adresseEmail", adresseEmail);
    return    query.exec();
}

