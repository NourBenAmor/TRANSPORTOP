#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trajet.h"
#include <QMessageBox>
#include<QDebug>
#include <QtDebug>
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabtrajet->setModel(tmptrajet.afficher());

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int num = ui->lineEdit_num->text().toInt();
    QString stationa= ui->lineEdit_stationa->text();
    QString stationd= ui->lineEdit_stationd->text();
    QString datea= ui->lineEdit_datea->text();
    QString dated= ui->lineEdit_dated->text();

  Trajet e(num,stationa,stationd,datea,dated);
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


}

void MainWindow::on_pb_supprimer_clicked()
{
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


void MainWindow::on_pb_modifier_clicked()
{
    int num = ui->lineEdit_numm->text().toInt();
    QString stationa= ui->lineEdit_stationam->text();
    QString stationd= ui->lineEdit_stationdm->text();
    QString datea= ui->lineEdit_dateam->text();
    QString dated= ui->lineEdit_datedm->text();
bool test=tmptrajet.modifier(num,stationa,stationd,datea,dated);

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

void MainWindow::on_pushButton_clicked()
{
    ui->tablea->setModel(tmptrajet.afficher2());


}



void MainWindow::on_lineEdit_numr_textChanged(const QString &arg1)
{    QString num= ui->lineEdit_numr->text();

    ui->tabler->setModel(tmptrajet.afficher3(num));
}

void MainWindow::on_lineEdit_numra_textChanged(const QString &arg1)
{QString num= ui->lineEdit_numra->text();

    ui->tableView->setModel(tmptrajet.afficher4(num));

}
