 #include "trajet.h"
#include <QDebug>
Trajet::Trajet()
{
num=0;
stationa="";
stationd="";
datea="";
dated="";

}
Trajet::Trajet(int num,QString stationa,QString stationd,QString datea,QString dated)
{
  this->num=num;
  this->stationa=stationa;
  this->stationd=stationd;
    this->datea=datea;
    this->dated=dated;


}
QString Trajet::get_stationa(){return  stationa;}
QString Trajet::get_stationd(){return stationd;}
QString Trajet::get_datea(){return datea;}
QString Trajet::get_dated(){return dated;}

int Trajet::get_num(){return  num;}

bool Trajet::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("INSERT INTO tabtrajet (num, stationa, stationd,datea,dated) "
                    "VALUES (:num, :stationa, :stationd, :datea, :dated)");
query.bindValue(":num", res);
query.bindValue(":stationa", stationa);
query.bindValue(":stationd", stationd);
query.bindValue(":datea", datea);
query.bindValue(":dated", dated);


return    query.exec();
}

QSqlQueryModel *Trajet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tabtrajet ORDER BY stationa  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("stationa "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("stationd"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datea"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dated"));

    return model;
}
QSqlQueryModel *Trajet::afficher2()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tabtrajet ORDER BY stationa  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("stationa "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("stationd"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datea"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dated"));

    return model;
}
QSqlQueryModel *Trajet::afficher3(QString num)
{
    QSqlQueryModel * model= new QSqlQueryModel();




model->setQuery("select * from tabtrajet where num like '"+num+"%' ");


model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("stationa "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("stationd"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datea"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dated"));

    return model;
}
QSqlQueryModel *Trajet::afficher4(QString num)
{
    QSqlQueryModel * model= new QSqlQueryModel();




model->setQuery("select * from tabtrajet where num like '"+num+"' ");


model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("stationa "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("stationd"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datea"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dated"));

    return model;
}

bool Trajet::supprimer(int num)
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("Delete from tabtrajet where num = :num ");
query.bindValue(":num", res);
return    query.exec();
}
bool Trajet::modifier(int num,QString stationa,QString stationd,QString datea,QString dated)
{QSqlQuery query;
    QString res= QString::number(num);


    query.prepare("UPDATE tabtrajet SET STATIONA=:stationa, STATIOND=:stationd, DATEA= :datea, DATED= :dated WHERE NUM=:num");

    query.bindValue(":num", res);
    query.bindValue(":stationa", stationa);
    query.bindValue(":stationd", stationd);
    query.bindValue(":datea", datea);
    query.bindValue(":dated", dated);


    return    query.exec();

}























