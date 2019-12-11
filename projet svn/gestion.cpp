#include "gestion.h"
#include "ui_gestion.h"
#include "convention.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>

gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    QPixmap pix2("C:/Users/hp/Desktop/projet/Transport/t.png");
        ui->labelB->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->labelB_2->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->labelB_3->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->labelB_4->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->labelB_5->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
    ui->tabConventions->setModel(tmpConvention.afficher());
    ui->lineEdit_Note->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_id_2->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Note_3->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_dateAjout->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_dateAjout_3->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Montantapayer->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Nom2emepartie->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_NomConvention->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Montantapayer_3->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Nom2emepartie_3->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_NomConvention_3->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
}

gestion::~gestion()
{
    delete ui;
}


void gestion::on_pb_ajouter_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
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
ui->lineEdit_NomConvention->clear();
ui->lineEdit_Nom2emepartie->clear();
ui->lineEdit_Note->clear();
ui->lineEdit_Montantapayer->clear();
ui->lineEdit_dateAjout->clear();

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
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    int n=ui->lineEdit_id_2->text().toInt();
    bool test = tmpConvention.supprimer(n);
    if(test)
    {
        ui->tabConventions->setModel(tmpConvention.afficher()); //refresh
        QMessageBox::information(nullptr,QObject::tr("supprimer une convention"),QObject::tr("Convention supprimée.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
        ui->lineEdit_id_2->clear();
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("supprimer une convention"),QObject::tr("Erreur !.\n"
                                                                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }
}



void gestion::on_pushButton_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
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
ui->lineEdit_NomConvention_3->clear();
ui->lineEdit_Nom2emepartie_3->clear();
ui->lineEdit_dateAjout_3->clear();
ui->lineEdit_Montantapayer_3->clear();
ui->lineEdit_Note_3->clear();
}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un événement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_pushButtonReOk_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    QSqlQuery query;
    QString id = ui->lineEditRecherche->text();
    id=id+"%";
    query.prepare("SELECT * from Réservation where(NUMRESERVATION LIKE :id)");
    query.bindValue(":id",id);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    qDebug()<<modal->rowCount();
    ui->tabRecherche_2->setModel(modal);
}
