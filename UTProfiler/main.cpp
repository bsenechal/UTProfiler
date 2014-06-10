/**
 * \file main.cpp
 * \author David Martins
 * \author Benoît Sénéchal
 * \version 1.0
 * \date 15 Juin 2014
 *
 */

#include "dbmanager.h"
#include <QApplication>
#include "accueil.h"
#include "filieres.h"


/**
 * \fn int main (int argc, char* argv[])
 * \brief Entrée du programme.
 *
 * \return app.exec() - Arrêt normal du programme.
 */


int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    /*! Initialisation de la BDD */
    dbmanager *db = dbmanager::getInstance();
    //db->dbinitialise("QSQLITE","/Users/David/Desktop/UTC/LO21/Projet/UTprofilerv3/UTProfiler/BDD/UTProfiler");
    db->dbinitialise("QSQLITE","C:/Users/Benoît/Documents/workspace/UTProfiler/BDD/UTProfiler");

    Accueil acc;
    acc.show();


   /* InsertUv ins;
    ins.show();

    ViewUv v;
    v.show();
*/
    return app.exec();
}
