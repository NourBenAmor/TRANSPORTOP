#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"connexion.h"
#include "trajet.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


   void on_pb_modifier_clicked();



   void on_pushButton_clicked();


   void on_lineEdit_numr_textChanged(const QString &arg1);

   void on_lineEdit_numra_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Trajet tmptrajet;
};

#endif // MAINWINDOW_H
