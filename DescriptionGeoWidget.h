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
 * Cette classe représente un widget qui se trouve dans la toolbox.
 * Il agit en faite comme un conteneur des autres formulaire de la meme catégorie.
 * @brief The DescriptionGeoWidget class
 */
class DescriptionGeoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DescriptionGeoWidget(Data * data, QWidget *parent = 0);
    
signals:

    /**
     * Ce signal est émis quand un nouvelle objet metallisation est créé
     * @brief newMetalCreated
     */
    void newMetalCreated(elementBase*);
    /**
     * Ce signal est émis quand un nouvelle objet parallelepipede est créé
     * @brief newParaCreated
     */
    void newParaCreated(elementBase*);
    /**
     * Ce signal est émis quand un nouvelle objet elementLocalise est créé
     * @brief newElemLocCreated
     */
    void newElemLocCreated(elementBase*);
    
public slots:

    /**
     * Cette fonction ouvre un formulaire pour ajouter un objet elementLocalise
     * @brief openElementLocaliseWindows
     */
    void openElementLocaliseWindows();
    
};

#endif // DESCRIPTIONGEOWIDGET_H
