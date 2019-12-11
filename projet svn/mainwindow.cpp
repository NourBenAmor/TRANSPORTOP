#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));

    QPixmap pix("C:/Users/hp/Desktop/EMPLOYE_ (1)/EMPLOYE_/t.png");
     ui->label_3->setPixmap(pix.scaled(1000,1000,Qt::KeepAspectRatio));
    QPixmap pix1("C:/Users/hp/Desktop/EMPLOYE_ (1)/EMPLOYE_/Capture.png");
    ui->label_2->setPixmap(pix1.scaled(750,300,Qt::KeepAspectRatio));

    //ui -> lineEdit_password->setEchoMode(QLineEdit::NoEcho);
   // ui->label_3->setStyleSheet("color: white;");

    ui->lineEdit_username->setStyleSheet("color: white;"
                            "background-color: black;"
                                         //"border-width: 5px;"
                                         "border-radius: 10px;"
                                         "font: bold 14px;"
                                         );
    ui->lineEdit_password->setStyleSheet("color: white;"
                            "background-color: black;"
                                         //"border-width: 5px;"
                                         "border-radius: 10px;"
                                         "font: bold 14px;"
                                         );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    gestion r;
    r.setModal(true);
    r.exec();
}

    /*
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    classEmployee e;
    int poste;
    QString username = ui->lineEdit_username->text();
    QString password = ui ->lineEdit_password->text();
    ui->lineEdit_password->clear();
    ui->lineEdit_username->clear();
    if (e.verifierCompte(username,password)==2||e.verifierCompte(username,password)==1)
    {
            poste=e.verifierStatut(username,password);

        if (poste==0)
        {
            QMessageBox::information(this, "login","Admin");
            Employe r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==1)
        {
            QMessageBox::information(this, "login","Agent de Réservation");
            Reservation r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==2)
        {
            QMessageBox::information(this, "login","Agent Bus");
            Bus r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==3)
        {
            QMessageBox::information(this, "login","Agent Trajet");
            gestionTrajet r;
            r.setModal(true);
            r.exec();
        }
        else if (poste==4)
        {
            QMessageBox::information(this, "login","Agent Trajet");
            gestionTrajet r;
            r.setModal(true);
            r.exec();//promotion
        }
        else if (poste==5)
        {
            QMessageBox::information(this, "login","Agent de Convention");
            gestion r;
            r.setModal(true);
            r.exec();
        }
    }
    else
    {
       QMessageBox::warning(this, "login","username and password are not correct");
    }
}
*/
