#include "gestion.h"
#include "ui_gestion.h"
#include "convention.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QSqlError>
gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    ui->tabConventions->setModel(tmpConvention.afficher());
}

gestion::~gestion()
{
    delete ui;
}


void gestion::on_pb_ajouter_clicked()
{
    int NumConvention = ui->lineEdit_NomConvention-> text().toInt();
    QString Nom2emepartie= ui->lineEdit_Nom2emepartie->text();
    QString Note= ui->lineEdit_Note->text();
    QString Montantapayer=ui->lineEdit_Montantapayer->text();
    QString date=ui->lineEdit_dateAjout->text();
  Convention c(NumConvention,Nom2emepartie,Montantapayer,date,Note);
  bool test=c.ajouter();
  if(test)
{
      afficherC();
 ui->tabConventions->setModel(tmpConvention.afficher());

QMessageBox::information(nullptr, QObject::tr("Ajouter une convention"),
                  QObject::tr("Convention ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une convention"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::afficherC()
{
    Convention c;
    c.afficher();
    delete ui;
}



void gestion::on_pb_supprimer_clicked()
{
    int n=ui->lineEdit_id_2->text().toInt();
    bool test = tmpConvention.supprimer(n);
    if(test)
    {
        ui->tabConventions->setModel(tmpConvention.afficher()); //refresh
    //    QMessageBox::information(nullptr,QObject::tr("supprimer une convention"),QObject::tr("trajet supprimé.\n"
       //"Click Cancel to exit.",QMessageBox::Cancel));
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("supprimer une convention"),QObject::tr("Erreur !.\n"
                                                                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }
}



void gestion::on_pushButton_clicked()
{
    int Num = ui->lineEdit_NomConvention_3->text().toInt();
    QString Nom= ui->lineEdit_Nom2emepartie_3->text();
    QString Date= ui->lineEdit_dateAjout_3->text();
    QString Montant= ui->lineEdit_Montantapayer_3->text();
    QString Note=ui->lineEdit_Note_3->text();
    //Convention c(Num,Nom,Montant,Date,Note);

  bool test=tmpConvention.modifier(Num,Nom,Montant,Date,Note);
  if(test)
  {
     ui->tabConventions->setModel(tmpConvention.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un évenement"),
                  QObject::tr("Evenement Modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un événement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString NumConvention = ui->lineEdit_NumConvention_2->text();
    NumConvention=NumConvention+"%";
    query.prepare("SELECT * from Convention where(NUMCONVENTION LIKE :NumConvention)");
    query.bindValue(":NumConvention",NumConvention);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    qDebug()<<modal->rowCount();
    ui->tabRecherche_2->setModel(modal);
}
