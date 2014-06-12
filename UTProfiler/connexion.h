/**
  * @file connexion.h
  */

#ifndef CONNEXION_H
#define CONNEXION_H

#include "singleton.h"
#include <QObject>
#include <QMessageBox>

class Connexion : public Singleton<Connexion>
{
friend class Singleton<Connexion>;
private:
    QString login;
    QString passwd;
    QString nom;
    QString prenom;
    QString sexe;
    QString date_naissance;
    QString email;
    QString commentaires;
    Connexion () {}
    ~Connexion (){}


public:
    QString connexion(QString login, QString mdp);
    bool isConnected() const { return !(this->login.isNull() && this->passwd.isNull()); } 
    void setLogin(QString l) { this->login = l;}
    void setPasswd(QString p) { this->passwd = p;}
    void setNom(QString n) { this->nom = n;}
    void setPrenom(QString p) { this->prenom = p;}
    void setSexe(QString s) { this->sexe = s;}
    void setDate_naissance(QString d) { this->date_naissance = d;}
    void setEmail(QString e) { this->email = e;}
    void setCommentaires(QString c) { this->commentaires = c;}
    QString getLogin() const { return this->login; }
    QString getPasswd() const { return this->passwd; }
    QString getNom() const { return this->nom; }
    QString getPrenom() const { return this->prenom; }
    QString getSexe() const { return this->sexe; }
    QString getDate_naissance() const { return this->date_naissance; }
    QString getEmail() const { return this->email; }
    QString getCommentaires() const { return this->commentaires; }
};

#endif // CONNEXION_H
