#include "employe.h"
#include "ui_employe.h"
#include <QMessageBox>
#include <QPixmap>
#include <QSound>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QPrintDialog>
#include <QPrinter>
Employe::Employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employe)
{
    ui->setupUi(this);
    QPixmap pix2("C:/Users/hp/Desktop/projet/Transport/t.png");
        ui->label_21->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->label_22->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->label_23->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->label_24->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));
        ui->label_25->setPixmap(pix2.scaled(800,700,Qt::KeepAspectRatio));

        ui->lineEdit_id->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_cin->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_nom->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_id_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_id_3->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_cin_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_cin_3->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_nom_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_nom_4->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_poste->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_telephone_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_telephone->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_prenom->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_adresse_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_adresse->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );
        ui->lineEdit_prenom_2->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-width: 5px;"
                                             "border-radius: 10px;"
                                             "font: bold 14px;"
                                             );

    ui->tabemploye->setModel(tmpemploye.afficher());


    QColor fontBold; fontBold.setBlue(true);
    //ui->tabWidget->setFont(fontBold);

    this->setWindowTitle("GESTION DES EMPLOYES");
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));
}

Employe::~Employe()
{
    delete ui;
}


void Employe::on_pb_ajouter_clicked()
{
    //QSound bts("C:/Users/walid/Documents/s.wav");
    //bts.play();

    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString telephone= ui->lineEdit_telephone->text();
    QString cin= ui->lineEdit_cin->text();
    QString poste= ui->comboBox->currentText();


  classEmployee e(id,nom,prenom,adresse,telephone,cin,poste);
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

void Employe::on_pb_supprimer_clicked()
{
 //   QSound bts("C:/Users/walid/Documents/s.wav");
   // bts.play();

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
void Employe::on_update_clicked()
{
 //   QSound bts("C:/Users/walid/Documents/s.wav");
   // bts.play();

    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_4->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    QString telephone= ui->lineEdit_telephone_2->text();
    QString cin= ui->lineEdit_cin_3->text();
    QString poste= ui->lineEdit_poste->text();

    classEmployee e(id,nom,prenom,adresse,telephone,cin,poste);
    bool test=e.update();


    if(test)
    {ui->tabemploye->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un employé"),
                    QObject::tr("Employé modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier Un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}




void Employe::on_search_clicked()
{
    QString val = ui->lineEdit_cin_2->text();

        ui->tabemploye_2->setModel(tmpemploye.afficher2(val));
}



void Employe::on_pdf_clicked()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->tabemploye->model()->rowCount();
       const int columnCount = ui->tabemploye->model()->columnCount();
       out <<"<html>\n"
             "<head>\n"
              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           << "<title>ERP - COMmANDE LIST<title>\n "
           << "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"

              "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
             "</br> </br>";
       // headers
       out << "<thead><tr bgcolor=#d6e5ff>";
       for (int column = 0; column < columnCount; column++)
           if (!ui->tabemploye->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tabemploye->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++) {
           out << "<tr>";
           for (int column = 0; column < columnCount; column++) {
               if (!ui->tabemploye->isColumnHidden(column)) {
                   QString data =ui->tabemploye->model()->data(ui->tabemploye->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table>\n"
           "</body>\n"
           "</html>\n";

       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QPrinter printer;

       QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
       if (dialog->exec() == QDialog::Accepted) {
           document->print(&printer);
       }

       delete document;
}
