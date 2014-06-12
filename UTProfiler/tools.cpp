#include "tools.h"
/**
 * @file semestre.cpp
 */

/**
 * @fn void Tools::switch_current_item(QListWidget *liste1,  QListWidget *liste2)
 * @param QListWidget *liste1
 * @param QListWidget *liste2
 * @brief Supprime l'item actuellement selectionné par l'utilisateur de la liste 1 et l'ajoute à la liste 2
 * @return void
 */
void Tools::switch_current_item(QListWidget *liste1,  QListWidget *liste2) {
    if (liste1->currentItem() != NULL) {
            liste2->addItem(liste1->currentItem()->text());
            delete liste1->currentItem();
        }
}

/**
 * @fn void Tools::enable_combobox(QComboBox *cbox, const QStringList& liste)
 * @param QComboBox *cbox
 * @param const QStringList& liste
 * @brief Ajoute le contenu de la liste à la combobox et active cette dernière
 * @return void
 */
void Tools::enable_combobox(QComboBox *cbox, const QStringList& liste){
    cbox->clear();
    cbox->addItem("");
    cbox->addItems(liste);
    cbox->setEnabled(true);
}

/**
 * @fn void Tools::maj_liste(QListWidget *liste, QSqlQuery query)
 * @param QListWidget *liste
 * @param QSqlQuery query
 * @brief Parcours le resultat de la requête SQL et l'ajoute à la liste
 * @return void
 */
void Tools::maj_liste(QListWidget *liste, QSqlQuery query){
    liste->clear();
    while(query.next()) {
          liste->addItem(query.value(0).toString());
        }
}
