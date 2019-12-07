#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QDialog>
#include <classemployee.h>

namespace Ui {
class Employe;
}

class Employe: public QDialog
{
    Q_OBJECT

public:
    explicit Employe(QWidget *parent = nullptr);
    ~Employe();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_update_clicked();

    void on_search_clicked();




    void on_pdf_clicked();

private:
    Ui::Employe *ui;
    classEmployee tmpemploye;
};

#endif // EMPLOYE_H
