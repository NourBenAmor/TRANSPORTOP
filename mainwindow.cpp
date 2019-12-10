#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include "promtion.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabemployer_2->setModel(tmp.afficher_Promotion());
    ui->tabemployer_2->setModel(tmp.afficher_Promotion());
    player = new QMediaPlayer(this);
    refresh();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::refresh()
{
  ui->tabemployer->setModel(tmp.afficher_Promotion());
  ui->comboBox_3->setModel(tmp.afficher_list());
  ui->comboBox_5->setModel(tmp.afficher_list());

}

void MainWindow::on_ajouter_clicked()
{    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/promo/promo/son/ah.mp3"));
     player->play();
    QString id=ui->ID->text();
    QString nom=ui->nom->text();
    QString datedebut=ui->dateEdit->date().toString();
    QString datefin=ui->dateEdit_2->date().toString();
    QString contenu=ui->contenu->text();
    if(id=="")
    {
         refresh();
     QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Champ vide"),QMessageBox::Ok);
    }
     else {

     Promotion e(id,nom,datedebut,datefin,contenu);
     if(!e.existe(e.getid()))
         QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Promotion existe"),QMessageBox::Ok);
     else {

           bool test=e.ajouter_Promotion();
          ui->tabemployer->setModel(tmp.afficher_Promotion());
          ui->tabemployer_2->setModel(tmp.afficher_Promotion());
          notifier = new QSystemTrayIcon(this);
          notifier->setIcon(QIcon("notification.png"));
          notifier->show();
          notifier->showMessage("DATA BASE UPDATED ","Promotion  Ajouter ",QSystemTrayIcon::Information,10000);
          QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Promotion ajouté"),QMessageBox::Ok);


    }
}
            ui->ID->clear();
            ui->nom->clear();
            ui->dateEdit->clear();
            ui->dateEdit_2->clear();
            ui->contenu->clear();

}


void MainWindow::on_supprimer_clicked()
{   player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/promo/promo/son/ah.mp3"));
    player->play();
    QString id = ui->sup->text();
     Promotion e;
     e.setid(id);
     bool test=e.supprimer_Promotion();
     if(test)
   {     ui->comboBox_3->setModel(tmp.afficher_list());
         ui->comboBox_5->setModel(tmp.afficher_list());
         ui->tabemployer->setModel(tmp.afficher_Promotion());
         ui->tabemployer_2->setModel(tmp.afficher_Promotion());
         notifier = new QSystemTrayIcon(this);
         notifier->setIcon(QIcon("notification.png"));
         notifier->show();
         notifier->showMessage("DATA BASE UPDATED ","Promotion  Supprimé ",QSystemTrayIcon::Information,10000);
         QMessageBox::information(nullptr,QObject::tr("Supression"),QObject::tr("Promotion supprime"),QMessageBox::Ok);
    }
    else {
        QMessageBox::information(nullptr,QObject::tr("Supression"),QObject::tr("Promotion non supprime"),QMessageBox::Ok);
    }

}



void MainWindow::on_modifier_2_clicked()
{    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/promo/promo/son/ah.mp3"));
     player->play();
    tmp.setnom(ui->nom1->text());
    tmp.setdatedebut(ui->dateEdit_3->time().toString());
    tmp.setdatefin(ui->dateEdit_4->time().toString());
    tmp.setcontenu(ui->contenu1->text());

    bool test=tmp.modifier_Promotion();
 if(test){
     ui->comboBox_3->setModel(tmp.afficher_list());
     ui->comboBox_5->setModel(tmp.afficher_list());
     ui->tabemployer_2->setModel(tmp.afficher_Promotion());
     notifier = new QSystemTrayIcon(this);
     notifier->setIcon(QIcon("notification.png"));
     notifier->show();
     notifier->showMessage("DATA BASE UPDATED ","Promotion  Modifie ",QSystemTrayIcon::Information,10000);
     QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Promotion Modifiee"),QMessageBox::Ok);
}
else {
    QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Promotion non Modifier"),QMessageBox::Ok);
    refresh();
   }

}



void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
    tmp.setid(arg1);
    tmp.chercher();
    ui->nom1->setText(tmp.getnom());
    ui->dateEdit_3->setDate(QDate::fromString(tmp.getdatedebut()));
    ui->dateEdit_4->setDate(QDate::fromString(tmp.getdatefin()));
    ui->contenu1->setText(tmp.getcontenu());



}

void MainWindow::on_comboBox_5_activated(const QString &arg1)
{
    ui->sup->setText(arg1);

}



void MainWindow::on_lineEdit_19_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();

     query->prepare("SELECT * FROM PROMOTION WHERE ID LIKE'"+arg1+"%'");
     query->exec();
     model->setQuery(*query);
     ui->tabemployer->setModel(model);
}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{

    etat=arg1;
    ui->tabemployer->setModel(tmp.recherche(valeur,etat));
    refresh();
}





void MainWindow::on_pushButton_7_clicked()
{

}



void MainWindow::on_radioButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/promo/promo/son/ah.mp3"));
        player->play();
       ui->tabemployer->setModel(tmp.afficher_tri_ID());
}

void MainWindow::on_radioButton_4_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/promo/promo/son/ah.mp3"));
        player->play();
       ui->tabemployer->setModel(tmp.afficher_tri_ID_DESC());
}







