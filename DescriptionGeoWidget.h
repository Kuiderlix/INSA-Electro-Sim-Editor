#ifndef DESCRIPTIONGEOWIDGET_H
#define DESCRIPTIONGEOWIDGET_H

#include <QWidget>
#include "FormParallelepipede.h"
#include "FormMetallisation.h"
#include "FormVolumeCalcul.h"
#include "FormElementLocalise.h"
#include "FormParoi.h"
#include "Data.h"

/**
 * @brief Cette classe représente un widget qui se trouve dans la toolbox.
 * Il agit en faite comme un conteneur des autres formulaire de la meme catégorie.
 */
class DescriptionGeoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DescriptionGeoWidget(Data * data, QWidget *parent = 0);
    
signals:

    /**
     * @brief Ce signal est émis quand un nouvelle objet metallisation est créé
     */
    void newMetalCreated(elementBase*);
    /**
     * @brief Ce signal est émis quand un nouvelle objet parallelepipede est créé
     */
    void newParaCreated(elementBase*);
    /**
     * @brief Ce signal est émis quand un nouvelle objet elementLocalise est créé
     */
    void newElemLocCreated(elementBase*);
    
public slots:

    /**
     * @brief Cette fonction ouvre un formulaire pour ajouter un objet elementLocalise
     */
    void openElementLocaliseWindows();
    
};

#endif // DESCRIPTIONGEOWIDGET_H
