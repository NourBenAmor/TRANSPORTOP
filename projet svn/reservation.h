#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <classreservation.h>
#include <QMessageBox>
#include <QDebug>
#include <QMediaPlayer>
#include <QThread>
#include<QSqlError>
#include <QSound>
#include "QPixmap"
#include <QSortFilterProxyModel>
#include <QDate>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>

namespace Ui {
class Reservation;
}

class Reservation : public QDialog
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();
        classReservation tmpReservation;
        bool controle(QString);
        QMediaPlayer* player;
        void combo();
        void comboboxTrajetD();
        void comboboxTrajetA(QString);
        void comboboxDateD(QString,QString);
        void comboboxDateA(QString,QString,QString);
        void comboboxTrajetD2();
        void comboboxTrajetA2();
        void comboboxDateD2();
        void comboboxDateA2();
        void putBusID(QString,QString,QString,QString);
        void giveNumReservation();
private slots:
        void on_pushButtonValider_clicked();

        void on_pushButtonReSupp_clicked();

        void on_pushButtonReModif_clicked();

        void on_pushButtonRechModif_clicked();

        void on_pushButtonReOk_clicked();

        void on_pushButtonTri_clicked();

        void on_pushButtonLoad_clicked();

        void on_lineEditRecherche_textEdited(const QString &arg1);

        void on_lineEditRecherche_editingFinished();

        void on_pushButtonPDF_2_clicked();

        void on_comboBoxTD_currentTextChanged(const QString &arg1);

        void on_comboBoxTA_currentTextChanged(const QString &arg1);

        void on_comboBoxDHD_currentTextChanged(const QString &arg1);

        void on_comboBoxDHA_activated(const QString &arg1);

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
