#include "classemployee.h"
#include <QDebug>

classEmployee::classEmployee()
{
id=0;
nom="";
prenom="";
adresse="";
telephone="";
cin="";
poste="";
}
classEmployee::classEmployee(int id,QString nom,QString prenom,QString adresse,QString telephone,QString cin,QString poste)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->telephone=telephone;
  this->cin=cin;
    this->poste=poste;



}
QString classEmployee::get_nom(){return  nom;}
QString classEmployee::get_prenom(){return prenom;}
QString classEmployee::get_adresse(){return adresse;}
QString classEmployee::get_telephone(){return telephone;}
QString classEmployee::get_cin(){return cin;}
QString classEmployee::get_poste(){return poste;}

int classEmployee::get_id(){return  id;}

bool classEmployee::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employe (ID, NOM, PRENOM, ADRESSE, TELEPHONE, CIN, POSTE) "
                    "VALUES (:id, :nom, :prenom, :adresse, :telephone, :cin, :poste)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":cin", cin);
query.bindValue(":poste", poste);
qDebug()<<res<<endl;
qDebug()<<"nom"<<nom<<endl;
qDebug()<<"prenom"<<prenom<<endl;
return    query.exec();
}

QSqlQueryModel * classEmployee::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Employe ORDER BY Poste ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("POSTE"));


    return model;
}
QSqlQueryModel * classEmployee::afficher2(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from Employe where ID= '"+val+"'") ;


model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("POSTE"));

    return model;
}


bool classEmployee::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool classEmployee::update()
{
  QSqlQuery query;
  QString res= QString::number(id);
query.prepare("update Employe set ID= :id, NOM= :nom, PRENOM= :prenom , ADRESSE= :adresse, TELEPHONE= :telephone , CIN= :cin , POSTE= :poste where ID= :id") ;
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":cin", cin);
query.bindValue(":poste", poste);

return    query.exec();
}

void classEmployee::chercher()
{
}


int classEmployee::verifierStatut(QString login,QString password)
{
    QSqlQuery query;
    QString role;
    query.exec("SELECT POSTE FROM EMPLOYE WHERE ID='"+login+"'AND CIN='"+password+"'");
        qDebug()<<"role1"<<login;
               // query.first();

    while (query.next())
    {
        role=query.value("POSTE").toString();
    qDebug()<<"role"<<role;
    if (role=="Admin")
        return 0;
    else if (role=="Agent de réservation")
        return 1;
    else if (role=="Agent Bus")
        return 2;
    else if (role=="Agent Trajets")
        return 3;
    else if (role=="Agent Promotions")
        return 4;
    else
        return 5;
    }
    return 5;
}

int classEmployee::verifierCompte(QString login,QString password)
{
    QSqlQuery query;
    QString login1,password1;
    if (login=="" || password=="")
        return  0;
    query.exec("SELECT ID,CIN from Employe");
        query.last();
        login1=query.value("ID").toString();
        password1=query.value("CIN").toString();
        if (login1==login && password1==password)
        {
            qDebug()<<"mawjouda f le5er";
            return 1;
        }
            query.exec("SELECT ID,CIN from Employe");
            while (query.next())
            {
                login1=query.value("ID").toString();
                password1=query.value("CIN").toString();
                query.at();
                if (login1==login && password1==password)
                {
                    qDebug()<<"mawjouda mech f le5er";
                    return 2;
                }
            }
    qDebug()<<"mech mawjouda jemla";
    return 4;
}
