#include "convention.h"
#include <QMessageBox>
Convention::Convention()
{
    Note="";
    NumConvention=0;
    Montantapayer="";
    Nom2emepartie="";
    date="";
}
Convention::Convention(int NumConvention ,QString Nom2emepartie ,QString Montantapayer,QString date,QString Note)
{
    this->NumConvention=NumConvention;
    this->Nom2emepartie=Nom2emepartie;
    this->Montantapayer=Montantapayer;
    this->date=date;
    this->Note=Note;
}
bool Convention::ajouter()
{
QSqlQuery query;
QString res= QString::number(NumConvention);
query.prepare("INSERT INTO CONVENTION (NUMCONVENTION, NOM2EMEPARTIE, MONTANTAPAYER, DATEE, NOTE) "
                    "VALUES (:NumConvention, :Nom2emepartie, :Montantapayer, :date, :Note)");
query.bindValue(":NumConvention", res);
query.bindValue(":Montantapayer", Montantapayer);
query.bindValue(":date",date);
query.bindValue(":Nom2emepartie", Nom2emepartie);
query.bindValue(":Note",Note);
return    query.exec();
}

QSqlQueryModel * Convention::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Convention ORDER BY DATEE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NumConvention"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom2emepartie"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montantapayer "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));

    return model;
}
bool Convention::supprimer(int n)
{
    QSqlQuery query;
    QString res= QString::number(n);
    query.prepare("Delete from Convention where NUMCONVENTION = :NumConvention ");
    query.bindValue(":NumConvention",res);
    return query.exec();
}
bool Convention::modifier(int NumConvention,QString Nom2emepartie,QString Date,QString Montantapayer,QString Note)
{
    QSqlQuery query;
    QString res= QString::number(NumConvention);
    query.prepare("UPDATE Convention SET  NOM2EMEPARTIE=:Nom2emepartie ,MONTANTAPAYER=:Montantapayer , DATEE=:Date , NOTE=:note WHERE NUMCONVENTION =:NumConvention ");
    query.bindValue(":NumConvention", res);
    query.bindValue(":Nom2emepartie", Nom2emepartie);
    query.bindValue(":Montantapayer", Montantapayer);
    query.bindValue(":Date", Date);
    query.bindValue(":note", Note);

    return    query.exec();

}
