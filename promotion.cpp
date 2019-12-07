#include "promtion.h"
#include "connexion.h"
Promotion::Promotion()
{

}
Promotion::Promotion(QString c,QString n,QString p,QString m,QString a)
{
    id=c;
    nom=n;
    datedebut=p;
    datefin=m;
    contenu=a;


}
void Promotion::setid(QString c)
{
    id=c;
}
void Promotion::setnom(QString n)
{
    nom=n;
}
void Promotion::setdatedebut(QString p)
{
    datedebut=p;
}
void Promotion:: setdatefin(QString m)
{
    datefin=m;
}
void Promotion:: setcontenu(QString a)
{
    contenu=a;
}

QString Promotion:: getid()
{
    return  id;
}
QString Promotion:: getnom()
{
    return nom;
}
QString Promotion:: getdatedebut()
{
    return datedebut;
}
QString Promotion:: getdatefin()
{
    return datefin;
}
QString Promotion:: getcontenu()
{
    return contenu;
}

bool Promotion:: ajouter_Promotion()
{
    QSqlQuery query;

    query.prepare("INSERT INTO Promotion (id,nom,datedebut,datefin,contenu) " "VALUES (:id,:nom,:datedebut,:datefin,:contenu)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":contenu",contenu);
    return    query.exec();

}


bool Promotion::supprimer_Promotion()
{

    QSqlQuery query;
    query.prepare("Delete from Promotion where id = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
QSqlQueryModel * Promotion:: afficher_Promotion()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Promotion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedebut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datefin"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("contenu"));
    return model;
}

 bool Promotion::modifier_Promotion()
 {      QSqlQuery query;
        query.prepare("update Promotion set nom=:nom,datedebut=:datedebut,datefin=:datefin,contenu=:contenu where id=:id");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":datedebut",datedebut);
        query.bindValue(":datefin", datefin);
        query.bindValue(":contenu", contenu);


        return    query.exec();

}

QSqlQueryModel * Promotion:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select id from Promotion");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));


            return model;
}
void Promotion:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,datedebut,datefin,contenu FROM Promotion WHERE id =:id");
     query1.bindValue(":id",id);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     datedebut = query1.value(1).toString();
     datefin = query1.value(2).toString();
     contenu = query1.value(3).toString();
     }

}
QSqlQueryModel * Promotion:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM Promotion WHERE id LIKE :valeur order by id");}
    else   { query.prepare("SELECT * FROM Promotion WHERE id LIKE :valeur order by id desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datefin"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("contenu"));
    return model;

}
bool Promotion::existe(QString id)
{
    QSqlQuery query;

    query.prepare("select * from promotion where id like :id");
    QString id1="%"+id+"%";
    query.bindValue(":id",id1);
   if(query.exec())
       return true;
   else
       return false;



}
