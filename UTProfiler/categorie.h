/**
 * \file categorie.h
 */

#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Categorie : public Singleton<Categorie>
{
    friend class Singleton<Categorie>;
    QStringList liste_categories;
    /**
     * \fn Categorie()
     * \brief Construit une QStringList à partir des noms de chaque catégorie d'UV
     */
    Categorie();
public:
    /**
     * \fn getListe_categories()
     * \brief Retourne la liste des categories d'UV
     * \return QStringList&
     */
    QStringList& getListe_categories() { return this->liste_categories; }

    /**
     * \fn void push_back(QString item)
     * \brief Ajoute un élément à la fin de la liste d'UV
     * \param QString item
     * \return void
     */
    void push_back(QString item) { this->liste_categories.push_back(item); }

    /**
     * \fn void removeAt(int row)
     * \param int row
     * \brief Supprime l'élément de la liste d'UV présent à la ligne passé en paramètre
     * \return void
     */
    void removeAt(int row) { this->liste_categories.removeAt(row); }

    /**
     * \fn void setListe_categories(QStringList& l)
     * \param QStringList& l
     * \brief Setter pour la liste de catégories d'UV
     * \return void
     */
    void setListe_categories(QStringList& l) { this->liste_categories = l; }
};



#endif // CATEGORIE_H
