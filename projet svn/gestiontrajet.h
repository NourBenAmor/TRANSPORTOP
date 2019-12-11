#ifndef GESTIONTRAJET_H
#define GESTIONTRAJET_H

#include <QDialog>
#include <trajet.h>
#include <QMessageBox>
#include <QDebug>
#include <QSound>

namespace Ui {
class gestionTrajet;
}

class gestionTrajet : public QDialog
{
    Q_OBJECT

public:
    explicit gestionTrajet(QWidget *parent = nullptr);
    ~gestionTrajet();
        void comboboxBus();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_numr_textChanged(const QString &arg1);


private:
    Ui::gestionTrajet *ui;
    Trajet tmptrajet;
};

#endif // GESTIONTRAJET_H
