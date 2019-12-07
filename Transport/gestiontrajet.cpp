#include "gestiontrajet.h"
#include "ui_gestiontrajet.h"

gestionTrajet::gestionTrajet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionTrajet)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    comboboxBus();
    ui->tabtrajet->setModel(tmptrajet.afficher());
    QPixmap pix2("C:/Users/hp/Desktop/projet/Transport/t.png");
        ui->label_8->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->label_9->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->label_10->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->label_17->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->label_11->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
    ui->lineEdit_num->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_numm->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_numr->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_numt->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_datea->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_dated->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_dateam->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_datedm->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_stationa->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_stationd->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_stationam->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
    ui->lineEdit_stationdm->setStyleSheet("color: white;"
                            "background-color: black;"
                                         "border-radius: 10px;"
                                         "font: bold 10px;");
}

gestionTrajet::~gestionTrajet()
{
    delete ui;

}

void gestionTrajet::on_pb_ajouter_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    int num = ui->lineEdit_num->text().toInt();
    QString stationa= ui->lineEdit_stationa->text();
    QString stationd= ui->lineEdit_stationd->text();
    QString datea= ui->lineEdit_datea->text();
        qDebug()<<"fuck";
            qDebug()<<"stationa"<<stationa;
    QString dated= ui->lineEdit_dated->text();
    QString IdBus= ui->comboBoxIDBus_2->currentText();
  Trajet e(num,IdBus,stationd,dated,stationa,datea);
  bool test=e.ajouter();
  if(test)
{ui->tabtrajet->setModel(tmptrajet.afficher());//refresh
      ui->tablea->setModel(tmptrajet.afficher2());//refresh

QMessageBox::information(nullptr, QObject::tr("Ajouter un trajet"),
                  QObject::tr("trajet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un trajet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->lineEdit_num->clear();
ui->lineEdit_stationa->clear();
ui->lineEdit_stationd->clear();
ui->lineEdit_datea->clear();
ui->lineEdit_dated->clear();
}

void gestionTrajet::on_pb_supprimer_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    int num = ui->lineEdit_numt->text().toInt();
    bool test=tmptrajet.supprimer(num);
    if(test)
    {ui->tabtrajet->setModel(tmptrajet.afficher());//refresh
        ui->tablea->setModel(tmptrajet.afficher2());//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un trajet"),
                    QObject::tr("trajet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un trajet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionTrajet::comboboxBus()
{
    QSqlQuery query;
    query.prepare("select ETAT from BUS");


    query.prepare("select ID from BUS");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    //qDebug()<<modal->rowCount();
    ui->comboBoxIDBus->setModel(modal);
    ui->comboBoxIDBus_2->setModel(modal);
}

void gestionTrajet::on_pb_modifier_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    int num = ui->lineEdit_numm->text().toInt();
    QString stationa= ui->lineEdit_stationam->text();
    QString stationd= ui->lineEdit_stationdm->text();
    QString datea= ui->lineEdit_dateam->text();
    QString IdBus= ui->comboBoxIDBus->currentText();
    QString dated= ui->lineEdit_datedm->text();
bool test=tmptrajet.modifier(num,IdBus,stationd,dated,stationa,datea);

if (test)
  {  ui->tabtrajet->setModel(tmptrajet.afficher());//refresh
    ui->tablea->setModel(tmptrajet.afficher2());//refresh

QMessageBox::information(nullptr, QObject::tr("modifier un trajet"),
                QObject::tr("trajet modidier.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un trajet"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionTrajet::on_pushButton_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    ui->tablea->setModel(tmptrajet.afficher2());
}

void gestionTrajet::on_lineEdit_numr_textChanged(const QString &arg1)
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
       ui->tabler->setModel(tmptrajet.afficher3(arg1));
}
