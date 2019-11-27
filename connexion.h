#ifndef CONNEXION_H
#define CONNEXION_H
#include<QSqlDatabase>


class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool createconnection();
    void fermerconnection();
};

#endif // CONNEXION_H
