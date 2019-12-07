#include "reservation.h"
#include "ui_reservation.h"
#include "classreservation.h"


Reservation::Reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("C:/Users/hp/Desktop/projet/Transport/Icone.PNG"));
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    ui->tabReservation->setModel(tmpReservation.afficherReservation());
    QPixmap pix ("C:/Users/hp/Desktop/projet/Reservation/bus");
        //ui->labelpix->setPixmap(pix);

        QPixmap pix2("C:/Users/hp/Desktop/projet/Transport/t.png");
            ui->label_2->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
            ui->label_3->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
            ui->label_4->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
            ui->label_5->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
            ui->label_6->setPixmap(pix2.scaled(1000,1000,Qt::KeepAspectRatio));
        ui->lineEditAE->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->spinBoxNP->setStyleSheet("color: white;"
                                "background-color: black;"
                                          //   "border-radius: 10px;"
                                             );
      /*  ui->spinBoxNum->setStyleSheet("color: white;"
                                "background-color: black;"
                                          //   "border-radius: 10px;"
                                             );*/
        ui->spinBoxNPModif->setStyleSheet("color: white;"
                                "background-color: black;"
                                          //   "border-radius: 10px;"
                                             );
        ui->comboBoxTA->setStyleSheet("color: white;"
                                "background-color: black;"
                                            // "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->comboBoxTD->setStyleSheet("color: white;"
                                "background-color: black;"
                                             //"border-radius: 10px;"
                                             "font: bold 10px;");
        ui->comboBoxDHA->setStyleSheet("color: white;"
                                "background-color: black;"
                                            // "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->comboBoxDHD->setStyleSheet("color: white;"
                                "background-color: black;"
                                            // "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditP->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditPModif->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditReSupp->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditAEModif->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditReModif->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        ui->lineEditRecherche->setStyleSheet("color: white;"
                                "background-color: black;"
                                             "border-radius: 10px;"
                                             "font: bold 10px;");
        giveNumReservation();
}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::combo()
{
    comboboxTrajetD();
}
void Reservation::on_comboBoxTD_currentTextChanged(const QString &arg1)
{
        comboboxTrajetA(arg1);
}
void Reservation::on_comboBoxTA_currentTextChanged(const QString &arg1)
{
    QString TD=ui->comboBoxTD->currentText();
    comboboxDateD(TD,arg1);
}
void Reservation::on_comboBoxDHD_currentTextChanged(const QString &arg1)
{
    QString TD=ui->comboBoxTD->currentText();
    QString TA=ui->comboBoxTA->currentText();
    comboboxDateA(TD,TA,arg1);
}
void Reservation::on_comboBoxDHA_activated(const QString &arg1)
{
    QString TD=ui->comboBoxTD->currentText();
    QString TA=ui->comboBoxTA->currentText();
    QString DD=ui->comboBoxDHD->currentText();
    putBusID(TD,TA,DD,arg1);
}
void Reservation::putBusID(QString TD,QString TA,QString DD,QString arg1)
{
    QSqlQuery query;
    query.prepare("select BUS from tabtrajet where STATIOND=:TD AND DATED=:DD AND STATIONA=:TA AND DATEA=:arg1");
    query.bindValue(":TD",TD);
    query.bindValue(":TA",TA);
    query.bindValue(":DD",DD);
    query.bindValue(":arg1",arg1);
    query.exec();
    while (query.next())
    {
    ui->lineEditPBus->setText(query.value(0).toString());
    }
}
void Reservation::comboboxTrajetD()
{
    QSqlQuery query;
    query.prepare("select STATIOND from tabtrajet ");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    ui->comboBoxTD->setModel(modal);
}
void Reservation::comboboxTrajetD2()
{
    QSqlQuery query;
    query.prepare("select STATIOND from tabtrajet ");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    ui->comboBoxTDModif->setModel(modal);
}

void Reservation::comboboxTrajetA(QString TD)
{
    QSqlQuery query;
    query.prepare("select STATIONA from tabtrajet where STATIOND=:TD");
    qDebug()<<TD;
    query.bindValue(":TD",TD);
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    ui->comboBoxTA->setModel(modal);
}
void Reservation::comboboxTrajetA2()
{
    QSqlQuery query;
    query.prepare("select STATIONA from tabtrajet ");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    ui->comboBoxTAModif->setModel(modal);
}

void Reservation::comboboxDateA(QString TD,QString TA,QString arg1)
{
    QSqlQuery query;
    query.prepare("select DATEA from tabtrajet where STATIOND=:TD AND STATIONA=:TA AND DATED=:arg1");
    query.bindValue(":TD",TD);
    query.bindValue(":TA",TA);
    query.bindValue(":arg1",arg1);
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    //qDebug()<<modal->rowCount();
    ui->comboBoxDHA->setModel(modal);
}
void Reservation::comboboxDateA2()
{
    QSqlQuery query;
    query.prepare("select DATEA from tabtrajet ");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    //qDebug()<<modal->rowCount();
    ui->comboBoxDHAModif->setModel(modal);
}

void Reservation::giveNumReservation()
{
    QSqlQuery query;
    query.prepare("select NUMRESERVATION from Réservation");
    query.exec();
    query.last();
    ui->spinBoxNum->setValue(query.value(0).toInt()+1);
    ui->spinBoxNum->setEnabled(false);
    qDebug()<<query.value(1).toInt();
}

void Reservation::comboboxDateD(QString TD,QString arg1)
{
    QSqlQuery query;
    query.prepare("select DATED from tabtrajet where STATIOND=:TD AND STATIONA=:arg1");
        query.bindValue(":TD",TD);
        query.bindValue(":arg1",arg1);
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    //qDebug()<<modal->rowCount();
    ui->comboBoxDHD->setModel(modal);
}
void Reservation::comboboxDateD2()
{
    QSqlQuery query;
    query.prepare("select DATED from tabtrajet ");
    query.exec();
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    //qDebug()<<modal->rowCount();
    ui->comboBoxDHDModif->setModel(modal);
}


void Reservation::on_pushButtonValider_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();


    int nombreDePlace = ui->spinBoxNP->text().toInt();
    double prix=ui->lineEditP->text().toDouble();
    QString trajetD = ui->comboBoxTD->currentText();
    QString dateD =ui->comboBoxDHD->currentText();
    QString trajetA = ui->comboBoxTA->currentText();
    QString dateA =ui->comboBoxDHA->currentText();
    QString adresseEmail=ui->lineEditAE->text();
    classReservation r(nombreDePlace,prix,trajetD,dateD,trajetA,dateA,adresseEmail);
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

                    ui->spinBoxNP->clear();
                    ui->lineEditP->clear();
                    ui->lineEditAE->clear();
                    giveNumReservation();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Réservation"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

     }
        else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une Réservation"),
            QObject::tr("l'adresse Email doit être \nsous la forme xxx@xxx.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void Reservation::on_pushButtonReSupp_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();

    classReservation r;
    int numReservation = ui->lineEditReSupp->text().toInt();
    QString  num = QString::number(numReservation);
    QString string="Voulez-vous vraiment supprimer la réservation N°= "+num+" ??.";
    QString string1="La réservation N°= "+num+" est supprimée";
    const char* c= string.toStdString().c_str();
    const char* c1= string.toStdString().c_str();
    if (r.existeee(numReservation))
    {
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(nullptr, QObject::tr("Supprimer une Réservation"),
        QObject::tr(c), QMessageBox::Cancel|QMessageBox::Ok);
    if (reply==QMessageBox::Ok)
    {
        bool test=r.supprimer(numReservation);
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Supprimer une Réservation"),
                QObject::tr(c1), QMessageBox::Cancel);
            ui->lineEditReSupp->clear();
        }
    }
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une Réservation"),
                        QObject::tr("La réservation n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabReservation->setModel(tmpReservation.afficherReservation());
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
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    classReservation c;
    int nombreDePlace = ui->spinBoxNPModif->text().toInt();
    int numReservation = ui->lineEditReModif->text().toInt();
    double prix=ui->lineEditPModif->text().toDouble();
    QString trajetD = ui->comboBoxTD->currentText();
    QString dateD =ui->comboBoxDHD->currentText();
    QString trajetA = ui->comboBoxTA->currentText();
    QString dateA =ui->comboBoxDHA->currentText();
    QString adresseEmail=ui->lineEditAEModif->text();
    bool test=c.modification(numReservation,nombreDePlace,prix,trajetD,dateD,trajetA,dateA,adresseEmail);
    if (c.existeee(numReservation))
    {
    bool testAdresse=controle(adresseEmail);
    if (testAdresse)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(nullptr, QObject::tr("Supprimer une Réservation"),
            QObject::tr("c"), QMessageBox::Cancel|QMessageBox::Ok);
        if (reply==QMessageBox::Ok)
        {
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier une Réservation"),
                    QObject::tr("Réservation modifiée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tabReservation->setModel(tmpReservation.afficherReservation());
                ui->spinBoxNPModif->clear();
                ui->lineEditReModif->clear();
                ui->lineEditPModif->clear();
                ui->lineEditAEModif->clear();
            }
            else
            {
             QMessageBox::critical(nullptr, QObject::tr("Modifier un Réservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
    }
   else
    {
       QMessageBox::critical(nullptr, QObject::tr("Ajouter une Réservation"),
       QObject::tr("l'adresse Email doit être \nsous la forme xxx@xxx.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }

}


void Reservation::on_pushButtonRechModif_clicked()
{
    comboboxTrajetA2();
     comboboxTrajetD2();
     comboboxDateA2();
     comboboxDateD2();
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    classReservation c;
    int ival = ui->lineEditReModif->text().toInt();
    if (c.existeee(ival))
    {
    QString  val = QString::number(ival);
        QSqlQuery query;
        query.first();
        query.prepare("SELECT * from Réservation where NUMRESERVATION= '"+val+"'");
        if(query.exec())

        {
                            //query.value(1).toInt()
            while(query.next())
            {
                qDebug()<<"6="<<query.value(6).toString() << endl;
                qDebug()<<"1="<<query.value(1).toString() << endl;
                qDebug()<<"2="<<query.value(2).toString() << endl;
                qDebug()<<"3="<<query.value(3).toString() << endl;
                qDebug()<<"4="<<query.value(4).toString() << endl;
                qDebug()<<"5="<<query.value(5).toString() << endl;
                ui->spinBoxNPModif->setValue(query.value(1).toInt());//nombre de place
                ui->lineEditPModif->setText(query.value(2).toString());//prix
                ui->comboBoxTAModif->setCurrentText(query.value(6).toString());
                ui->comboBoxDHDModif->setCurrentText(query.value(2).toString());
                ui->comboBoxTDModif->setCurrentText(query.value(3).toString());
                ui->comboBoxDHAModif->setCurrentText(query.value(7).toString());
                ui->lineEditAEModif->setText(query.value(5).toString());//adressEmail
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Chercher Réservation!"),
                                  QObject::tr("Erreur!.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
        else
    {
        QMessageBox::critical(nullptr, QObject::tr("Chercher une Réservation"),
                    QObject::tr("La réservation n'existe pas !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEditReModif->clear();
    }
}


void Reservation::on_pushButtonReOk_clicked()
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

void Reservation::on_pushButtonTri_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
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


void Reservation::on_pushButtonLoad_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
          // comboboxTrajetA();
            //comboboxTrajetD();
    combo();
           // comboboxDateA();
            //comboboxDateD();
            giveNumReservation();
            ui->pushButtonLoad->hide();
}

void Reservation::on_lineEditRecherche_textEdited(const QString &arg1)
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
    QSqlQuery query;
    query.prepare("SELECT * from Réservation where(NUMRESERVATION LIKE :id)");
    query.bindValue(":id",arg1+"%");
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    qDebug()<<modal->rowCount();
    ui->tabRecherche_2->setModel(modal);
}

void Reservation::on_lineEditRecherche_editingFinished()
{
    QSqlQuery query;
    query.prepare("SELECT * from Réservation where(NUMRESERVATION LIKE :id)");
    query.bindValue(":id",-1);
    if(!query.exec())
    {
        qDebug()<<query.lastError();
    }
    QSqlQueryModel * modal= new QSqlQueryModel();
    modal->setQuery(query);
    qDebug()<<modal->rowCount();
    ui->tabRecherche_2->setModel(modal);
}


void Reservation::on_pushButtonPDF_2_clicked()
{
    QSound bts("C:/Users/hp/Desktop/projet/Transport/sound.wav");
    bts.play();
     QString strStream;
     QTextStream out(&strStream);

                const int rowCount = ui->tabReservation->model()->rowCount();
                const int columnCount = ui->tabReservation->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Réservations ****** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; margin:auto; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabReservation->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabReservation->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabReservation->isColumnHidden(column)) {
                            QString data =ui->tabReservation->model()->data(ui->tabReservation->model()->index(row, column)).toString().simplified();
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



