#include "promotion.h"
#include <QSqlQueryModel>
#include <QObject>

Promotion::Promotion()
{

}

Promotion::Promotion(int id,QString nom,QString datedebut,QString datefin,QString contenu)
{

    this->id=id;
    this->nom=nom;
    this->date_debut=datedebut;
    this->date_fin=datefin;
    this ->contenu=contenu;
}
void Promotion::setid(int id)
{
    this->id=id;
}
void Promotion::setnom(QString nom)
{
    this->nom=nom;
}
void Promotion::setcontenu(QString contenu)
{
    this->contenu=contenu;
}
void Promotion::setdatefin(QString datefin)
{
    this->date_fin=datefin;
}
void Promotion::setdatedebut(QString datedebut)
{
    this->date_debut=datedebut;
}
int Promotion::getid()
{
    return this->id;

}
QString Promotion::getnom()
{
    return this->nom;
}
QString Promotion::getdatefin()
{
    return this->date_fin;
}
QString Promotion::getdatedebut()
{
    return this->date_debut;
}
QString Promotion::getcontenu()
{
    return this->contenu;
}



bool Promotion::ajouterpromotion()
{
    QSqlQuery query;
    QString idd=QString::number(id);
    query.prepare("INSERT INTO promotion (id, nom, datedebut,datefin,contenu) VALUES (:id, :nom, :datedebut, :datefin,:contenu)");
    query.bindValue(":id",idd);
    query.bindValue(":nom",nom);
    query.bindValue(":datedebut",date_debut);
    query.bindValue(":datefin",date_fin);
    query.bindValue(":contenu",contenu);
    return  query.exec();

}
bool Promotion::supprimerpromotion(QString id)
{
    QSqlQuery query;
           query.prepare("DELETE FROM PROMOTION WHERE id='"+id+"'");
          query.addBindValue(id);
          return  query.exec();
}
bool Promotion::modifierpromotion(QString nom,QString date_debut, QString date_fin, QString id,QString contenu){
    QSqlQuery query;
    query.prepare("UPDATE promotion set nom='"+nom+"' where id='"+id+"'");
    query.bindValue(":nom",nom);
    query.prepare("UPDATE promotion set date_debut='"+date_debut+"' where date_debut='"+date_debut+"'");
    query.bindValue(":date_debut",date_debut);
    query.prepare("UPDATE promotion set date_fin='"+date_fin+"' where date_debut='"+date_fin+"'");
    query.bindValue(":date_fin",date_fin);

    query.prepare("UPDATE promotion set contenu='"+contenu+"' where id='"+id+"'");
    query.bindValue(":contenu",contenu);
    return query.exec();
}
QSqlQueryModel *Promotion:: consulter()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from promotion");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CONTENU"));

    return  model;

}

QSqlQueryModel *Promotion:: consulter2(QString a)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    if (a=="")
    {
        model->setQuery("select * from promotion order by id");

    }
    else
    {
        model->setQuery("select * from promotion where id='"+a+"' or nom='"+a+"'");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CONTENU"));

    return  model;

}
QSqlQueryModel *Promotion::consultertrie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from promotion order by ID ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEDEBUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEFIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CONTENU"));

    return  model;


}
