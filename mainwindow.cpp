#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include"promotion.h"
#include "connexion.h"
#include<QMessageBox>
#include<QDebug>
#include <QTextBrowser>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix(":/img/img/photo-1544620347-c4fd4a3d5957.jpg");
    //ui->label_5->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(index).toString();
    QSqlQuery q;
    q.prepare("SELECT * FROM promotion WHERE ID=?");
    q.addBindValue(id);
            if(q.exec())
    {
        while(q.next())
        {
            ui->lineEdit->setText(q.value(0).toString());
            ui->lineEdit_2->setText(q.value(1).toString());
            ui->dateEdit->setDate(q.value(2).toDate());
            ui->dateEdit_2->setDate(q.value(3).toDate());
            ui->lineEdit_4->setText(q.value(4).toString());
         }


    }
}

void MainWindow::on_pushButton_clicked()
{
    int id= ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString contenu=ui->lineEdit_4->text();
    QString datedebut=ui->dateEdit->date().toString();
    QString datefin=ui->dateEdit->date().toString();
    if(ui->dateEdit->date() < ui->dateEdit_2->date())
    {
    Promotion e(id,nom,datedebut,datefin,contenu);
    bool test=e.ajouterpromotion();
    if (test)
    {
        ui->tableView->setModel(tmppromo.consulter());
        QMessageBox::information(nullptr,QObject::tr("Ajout"),QObject::tr("Promotion ajouté"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Ajout"),QObject::tr("ID existe"),QMessageBox::Ok);



    }


    }
    else
       QMessageBox::critical(nullptr,QObject::tr("DAte "),QObject::tr("Impossible"),QMessageBox::Ok);



}

void MainWindow::on_pushButton_2_clicked()
{
    QString id= ui->lineEdit->text();
    QString nom=ui->lineEdit_2->text();
    QString datedebut=ui->dateEdit->date().toString();
    QString datefin=ui->dateEdit_2->date().toString();
    QString contenu=ui->lineEdit_4->text();

    bool test=tmppromo.modifierpromotion(nom,datedebut,datefin,id,contenu);
    if (test)
    {
        ui->tableView->setModel(tmppromo.consulter());
        QMessageBox::information(nullptr,QObject::tr("Modification"),QObject::tr("Promotion modifié"),QMessageBox::Ok);

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Modification"),QObject::tr("Erreur"),QMessageBox::Ok);

    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QString id= ui->lineEdit->text();
    bool test=tmppromo.supprimerpromotion(id);
    if (test)
    {
        ui->tableView->setModel(tmppromo.consulter());
        QMessageBox::information(nullptr,QObject::tr("Supression"),QObject::tr("Promotion supprimé"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Supression"),QObject::tr("Promotion supprimé"),QMessageBox::Ok);

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(tmppromo.consulter());
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    QString a=ui->lineEdit_3->text();
    ui->tableView->setModel(tmppromo.consulter2(a));



}

void MainWindow::on_pushButton_5_clicked()
{
     ui->tableView->setModel(tmppromo.consultertrie());
}

