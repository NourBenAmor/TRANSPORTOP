#ifndef CONVENTION_H
#define CONVENTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

namespace Ui {
class Convention;
}

class Convention : public QDialog
{
public:
   Convention();
   Convention(int,QString,QString,QString,QString);
   int getNumConvention() {return NumConvention ;}
   QString getNom2emepartie() {return Nom2emepartie ; }
   QString getNote() {return Note ;}
   QString getMontantapayer() {return Montantapayer ; }
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int);
   bool modifier(int NumConvention,QString Nom2emepartie,QString Montantapayer,QString Date,QString Note);



private slots:


   void on_pb_ajouter_2_clicked();

private:
    int NumConvention;
   QString Nom2emepartie,date,Note,Montantapayer;

};
#endif // CONVENTION_H
