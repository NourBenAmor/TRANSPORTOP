#include "gestion.h"
#include "ui_gestion.h"
#include "employe.h"
#include <QMessageBox>
#include <QPixmap>
#include <QSound>

gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)

{
ui->setupUi(this);
QPixmap pix2("C:/Users/walid/Documents/t.png");
    ui->label_21->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
    QPixmap pix3("C:/Users/walid/Documents/t.png");
        ui->label_22->setPixmap(pix3.scaled(800,700,Qt::KeepAspectRatio));
        QPixmap pix4("C:/Users/walid/Documents/t.png");
            ui->label_23->setPixmap(pix4.scaled(800,700,Qt::KeepAspectRatio));
            QPixmap pix5("C:/Users/walid/Documents/t.png");
                ui->label_24->setPixmap(pix5.scaled(800,700,Qt::KeepAspectRatio));

                QPixmap pix6("C:/Users/walid/Documents/t.png");
                    ui->label_25->setPixmap(pix6.scaled(800,700,Qt::KeepAspectRatio));

ui->tabemploye->setModel(tmpemploye.afficher());

this->setWindowTitle("GESTION DES EMPLOYES");
}

gestion::~gestion()
{
    delete ui;
}

void gestion::on_pb_ajouter_clicked()
{
    QSound bts("C:/Users/walid/Documents/s.wav");
    bts.play();

    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString telephone= ui->lineEdit_telephone->text();
    QString cin= ui->lineEdit_cin->text();

  Employe e(id,nom,prenom,adresse,telephone,cin);
  bool test=e.ajouter();
  if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Employé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion::on_pb_supprimer_clicked()
{
    QSound bts("C:/Users/walid/Documents/s.wav");
    bts.play();

int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpemploye.supprimer(id);
if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Employé supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void gestion::on_update_clicked()
{
    QSound bts("C:/Users/walid/Documents/s.wav");
    bts.play();

    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_4->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    QString telephone= ui->lineEdit_telephone_2->text();
    QString cin= ui->lineEdit_cin_3->text();

    Employe e(id,nom,prenom,adresse,telephone,cin);
    bool test=e.update();


    if(test)
    {ui->tabemploye->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                    QObject::tr("Client modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier Un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}




void gestion::on_search_clicked()
{
    QString val = ui->lineEdit_cin_2->text();

        ui->tabemploye_2->setModel(tmpemploye.afficher2(val));
}
