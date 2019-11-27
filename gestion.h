#ifndef GESTION_H
#define GESTION_H
#include <QDialog>
#include"employe.h"

namespace Ui {
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_update_clicked();



    void on_search_clicked();




    void on_tabemploye_activated(const QModelIndex &index);

private:
    Ui::gestion *ui;
    Employe tmpemploye;


};

#endif // GESTION_H
