#include "reservation.h"
#include "ui_reservation.h"
#include "classreservation.h"
#include <QSqlError>
#include <Qerreu
#include "QPixmap"
#include <QSortFilterProxyModel>



Reservation::Reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
    ui->tabReservation->setModel(tmpReservation.afficherReservation());
    QPixmap pix ("C:/Users/hp/Desktop/projet/Reservation/bus");
        ui->labelpix->setPixmap(pix);
}

Reservation::~Reservation()
{
    delete ui;
}


void Reservation::on_pushButtonValider_clicked()
{



    int numReservation = ui->lineEditNR->text().toInt();
    int nombreDePlace = ui->spinBoxNP->text().toInt();
    double prix=ui->lineEditP->text().toDouble();
    QString trajet = ui->lineTest3->text();
    QString date =ui->linetest4->text();
    QString adresseEmail=ui->lineEditAE->text();

    player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/Projet/click.MP3"));
       player->play();
       qDebug()<<player->errorString();
       QThread::sleep(1);

    classReservation r(numReservation,nombreDePlace,prix,trajet,date,adresseEmail);
    bool testAdresse=controle(adresseEmail);
    if (testAdresse)
    {
        bool test=r.ajouterReservation();
        if(test)
        {
            ui->tabReservation->setModel(tmpReservation.afficherReservation());
                    QMessageBox::information(nullptr, QObject::tr("Ajouter une Réservation"),
                        QObject::tr("Réservation ajoutée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

                    ui->lineEditNR->clear();
                    ui->spinBoxNP->clear();
                    ui->lineEditP->clear();
                    ui->lineTest3->clear();
                    ui->linetest4->clear();
                    ui->lineEditAE->clear();
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un Réservation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

     }
        else
        QMessageBox::information(nullptr, QObject::tr("Ajouter une Réservation"),
            QObject::tr("l'adresse Email doit être \nsous la forme xxx@xxx.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void Reservation::on_pushButtonReSupp_clicked()
{
    classReservation r;
    int numReservation = numRecherche();
    bool test=r.supprimer(numReservation);
    if(test)
                QMessageBox::information(nullptr, QObject::tr("Supprimer une Réservation"),
                    QObject::tr("Réservation supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
      else
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Réservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
        ui->tabReservation->setModel(tmpReservation.afficherReservation());
    }


int Reservation::numRecherche()
{
    int numReservation = ui->lineEditReSupp->text().toInt();
    return numReservation;
}

bool Reservation::controle(QString test)
{
    for(int i = 0; i < test.length(); i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}


void Reservation::on_pushButtonReModif_clicked()
{
    classReservation c;
    int nombreDePlace = ui->spinBoxNPModif->text().toInt();
    int numReservation = ui->lineEditReModif->text().toInt();
    double prix=ui->lineEditPModif->text().toDouble();
    QString trajet = ui->lineTest3Modif->text();
    QString date =ui->linetest4Modif->text();
    QString adresseEmail=ui->lineEditAEModif->text();
    bool test=c.modification(numReservation,nombreDePlace,prix,trajet,date,adresseEmail);
    bool testAdresse=controle(adresseEmail);
    if (testAdresse)
    {
            if(test)
                QMessageBox::information(nullptr, QObject::tr("Modifier une Réservation"),
                    QObject::tr("Réservation modifiée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            else
            {
             QMessageBox::information(nullptr, QObject::tr("Modifier un Réservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
            ui->tabReservation->setModel(tmpReservation.afficherReservation());
    }
   else
       QMessageBox::information(nullptr, QObject::tr("Ajouter une Réservation"),
       QObject::tr("l'adresse Email doit être \nsous la forme xxx@xxx.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);
    ui->spinBoxNPModif->clear();
    ui->lineEditReModif->clear();
    ui->lineEditPModif->clear();
    ui->lineTest3Modif->clear();
    ui->linetest4Modif->clear();
    ui->lineEditAEModif->clear();
}


void Reservation::on_pushButtonRechModif_clicked()
{
    int ival = ui->lineEditReModif->text().toInt();
    QString  val = QString::number(ival);
 qDebug()<< val << endl;
        QSqlQuery query;
        query.first();
        query.prepare("SELECT * from Réservation where NUMRESERVATION= '"+val+"'");
        if(query.exec())

        {
                            qDebug()<< query.value(6).toString() << endl;
                            //query.value(1).toInt()
            while(query.next())
            {

                ui->spinBoxNPModif->setValue(query.value(1).toInt());//nombre de place
                ui->lineEditPModif->setText(query.value(2).toString());//prix
                ui->lineTest3Modif->setText(query.value(3).toString());//trajet
                ui->linetest4Modif->setText(query.value(4).toString());//date
                ui->lineEditAEModif->setText(query.value(5).toString());//adressEmail
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Chercher Bus!"),
                                  QObject::tr("Erreur!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}


void Reservation::on_pushButtonReOk_clicked()
{
    QSqlQuery query;
    QString id = ui->lineEditRecherche->text();
    id=id+"%";
    qDebug()<<id;
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

void Reservation::on_pushButtonTri_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare("select * from Réservation");
        qry.exec();
        model->setQuery(qry);

        QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
        m->setDynamicSortFilter(true);
        m->setSourceModel(model);
        ui->tabReservation->setModel(m);
        ui->tabReservation->setSortingEnabled(true);
}
