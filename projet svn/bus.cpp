#include "bus.h"
#include "ui_bus.h"


Bus::Bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bus)
{
    ui->setupUi(this);
    ui->tabBUS->setModel(tmpBUS.afficher());
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));
    QPixmap pix2("C:/Users/hp/Desktop/projet/Transport/t.png");
        ui->labelB->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->labelB_2->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->labelB_3->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
    ui->lineEdit_IdBus->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Marque->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Capacite->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Chauffeur->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Matricule->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_Etat->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_Dispo->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_Marque->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_chercherSupp->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_chercherModif->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_Capacite->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_NomChauf->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_Modif_Matricule->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
}

Bus::~Bus()
{
    delete ui;
}

void Bus::on_pushButton_okAjout_clicked()
{
    int id = ui->lineEdit_IdBus->text().toInt();
    QString matricule= ui->lineEdit_Matricule->text();
    QString marque= ui->lineEdit_Marque->text();
    QString etat= ui->comboBox_Etat->currentText();
    int capacite= ui->lineEdit_Capacite->text().toInt();
    QString chauffeur= ui->lineEdit_Chauffeur->text();
    QString disponibilite= ui->comboBox_dispo->currentText();
  classBus B(id, matricule, marque, etat, capacite, chauffeur, disponibilite);
  bool test=B.ajouter();
  if(test)
{ui->tabBUS->setModel(tmpBUS.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Bus"),
                  QObject::tr("Bus ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Bus"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Bus::on_pushButton_chercherSupp_clicked()
{
    int id = ui->lineEdit_chercherSupp->text().toInt();
    bool test=tmpBUS.supprimer(id);
    if(test)
    {ui->tabBUS->setModel(tmpBUS.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Bus"),
                    QObject::tr("Bus supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Bus"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Bus::on_pushButton_chercherModif_clicked()
{
    QString val = ui->lineEdit_chercherModif->text();

        QSqlQuery query;
        query.prepare("select * from Bus where ID= ' "+val+" ' ");
        if(query.exec())
        {while(query.next())
            {
                ui->lineEdit_Modif_Matricule->setText(query.value(1).toString());
                ui->lineEdit_Modif_Marque->setText(query.value(2).toString());
                ui->lineEdit_Modif_Etat->setText(query.value(3).toString());
                ui->lineEdit_Modif_Capacite->setText(query.value(4).toString());
                ui->lineEdit_Modif_NomChauf->setText(query.value(5).toString());
                ui->lineEdit_Modif_Dispo->setText(query.value(6).toString());
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Chercher Bus!"),
                                  QObject::tr("Erreur!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void Bus::on_pushButton_Modif_Confirmer_clicked()
{
    int  id = ui->lineEdit_chercherModif->text().toInt();
    tmpBUS.supprimer(id);


    id = ui->lineEdit_chercherModif->text().toInt();
    QString matricule= ui->lineEdit_Modif_Matricule->text();
    QString marque= ui->lineEdit_Modif_Marque->text();
    QString etat= ui->comboBox_Modif_Etat->currentText();
    int capacite= ui->lineEdit_Modif_Capacite->text().toInt();
    QString chauffeur= ui->lineEdit_Modif_NomChauf->text();
    QString disponibilite= ui->comboBox_Modif_dispo->currentText();
  classBus B(id, matricule, marque, etat, capacite, chauffeur, disponibilite);
  bool test=B.ajouter();
  if(test)
{ui->tabBUS->setModel(tmpBUS.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un Bus"),
                  QObject::tr("Bus modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un Bus"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
