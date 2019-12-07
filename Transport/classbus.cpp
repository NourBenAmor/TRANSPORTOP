#include "classbus.h"


#include <QDebug>
#include <QString>
classBus::classBus()
{
    matricule="";
    marque="";
    etat="";
    chauffeur="";
    disponibilite="";
    id=0;
    capacite=0;
}

classBus::classBus(int id,QString matricule,QString marque,QString etat,int capacite,QString chauffeur,QString disponibilite)
{
    this->id=id;
    this->matricule=matricule;
    this->marque=marque;
    this->etat=etat;
    this->capacite=capacite;
    this->chauffeur=chauffeur;
    this->disponibilite=disponibilite;
}

int classBus::get_id(){return  id;}
int classBus::get_capacite(){return capacite;}
QString classBus::get_matricule(){return matricule;}
QString classBus::get_marque(){return marque;}
QString classBus::get_etat(){return etat;}
QString classBus::get_chauffeur(){return chauffeur;}
QString classBus::get_disponibilite(){return disponibilite;}

bool classBus::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO BUS (ID, MATRICULE, MARQUE, ETAT, CAPACITE, CHAUFFEUR, DISPONIBILITE) "
                    "VALUES (:id, :matricule, :marque, :etat, :capacite, :chauffeur, :disponibilite)");
query.bindValue(":id", res);
query.bindValue(":matricule", matricule);
query.bindValue(":marque", marque);
query.bindValue(":etat", etat);
query.bindValue(":capacite", capacite);
query.bindValue(":chauffeur", chauffeur);
query.bindValue(":disponibilite", disponibilite);

return    query.exec();
}

QSqlQueryModel * classBus::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from BUS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Matricule"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Marque"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Etat"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Capacite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Chauffeur"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Disponibilite"));
    return model;
}

bool classBus::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from BUS where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
