#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "promtion.h"
#include <QMainWindow>
#include <QtMultimedia>
#include <QSystemTrayIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();

private slots:
    void on_ajouter_clicked();



    void on_supprimer_clicked();

    void on_modifier_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_5_activated(const QString &arg1);

    void on_lineEdit_19_textChanged(const QString &arg1);

    void on_checkBox_2_stateChanged(int arg1);


    void on_pushButton_7_clicked();


    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();




    void on_tabemployer_activated(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Promotion tmp;
    int etat=0;
    QString valeur ="";
    QMediaPlayer *player;
    QSystemTrayIcon *notifier;
};
#endif // MAINWINDOW_H
