#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <classreservation.h>
#include <QMessageBox>
#include <QDebug>
#include <QMediaPlayer>
#include <QThread>

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
        int numRecherche();
        bool controle(QString);
        QMediaPlayer* player;

private slots:
        void on_pushButtonValider_clicked();

        void on_pushButtonReSupp_clicked();

        void on_pushButtonReModif_clicked();

        void on_pushButtonRechModif_clicked();

        void on_pushButtonReOk_clicked();

        void on_pushButtonTri_clicked();

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
