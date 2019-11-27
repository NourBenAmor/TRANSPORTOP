#include "employe.h"
#include <QDebug>
Employe::Employe()
{
id=0;
nom="";
prenom="";
adresse="";
telephone="";
cin="";

}
Employe::Employe(int id,QString nom,QString prenom,QString adresse,QString telephone,QString cin)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->telephone=telephone;
  this->cin=cin;


}
QString Employe::get_nom(){return  nom;}
QString Employe::get_prenom(){return prenom;}
QString Employe::get_adresse(){return adresse;}
QString Employe::get_telephone(){return telephone;}
QString Employe::get_cin(){return cin;}

int Employe::get_id(){return  id;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employe (ID, NOM, PRENOM, ADRESSE, TELEPHONE, CIN) "
                    "VALUES (:id, :nom, :prenom, :adresse, :telephone, :cin)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":cin", cin);

return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Employe ORDER BY Prenom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}
QSqlQueryModel * Employe::afficher2(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Employe where ID= '"+val+"'") ;


model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}


bool Employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Employe::update()
{
  QSqlQuery query;
  QString res= QString::number(id);
query.prepare("update Employe set ID= :id, NOM= :nom, PRENOM= :prenom , ADRESSE= :adresse, TELEPHONE= :telephone , CIN= :cin where ID= :id") ;
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":cin", cin);

return    query.exec();
}

void Employe::chercher()
{
}
