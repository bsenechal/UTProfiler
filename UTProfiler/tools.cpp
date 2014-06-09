#include "tools.h"

Tools::Tools()
{
}

void Tools::switch_current_item(QListWidget *liste1,  QListWidget *liste2) {
    if (liste1->currentItem() != NULL) {
            liste2->addItem(liste1->currentItem()->text());
            delete liste1->currentItem();
        }
}

void Tools::enable_combobox(QComboBox *cbox, const QStringList& liste){
    cbox->clear();
    cbox->addItem("");
    cbox->addItems(liste);
    cbox->setEnabled(true);
}

void Tools::maj_liste(QListWidget *liste, QSqlQuery query){
    liste->clear();
    while(query.next()) {
          liste->addItem(query.value(0).toString());
        }
}
