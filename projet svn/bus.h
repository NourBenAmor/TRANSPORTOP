#ifndef BUS_H
#define BUS_H

#include <QDialog>
#include <QMessageBox>
#include <classbus.h>
namespace Ui {
class Bus;
}

class Bus : public QDialog
{
    Q_OBJECT

public:
    explicit Bus(QWidget *parent = nullptr);
    ~Bus();

private slots:
    void on_pushButton_okAjout_clicked();

    void on_pushButton_chercherSupp_clicked();

    void on_pushButton_chercherModif_clicked();

    void on_pushButton_Modif_Confirmer_clicked();

private:
    Ui::Bus *ui;
    classBus tmpBUS;
};

#endif // BUS_H
