#ifndef DESCRIPTIONGEOWIDGET_H
#define DESCRIPTIONGEOWIDGET_H

#include <QWidget>
#include "FormParallelepipede.h"
#include "FormMetallisation.h"
#include "FormVolumeCalcul.h"
#include "FormElementLocalise.h"
#include "FormParoi.h"
#include "ToolBoxWidget.h"

/**
 * @brief Cette classe représente un widget qui se trouve dans la toolbox.
 * Il agit en faite comme un conteneur des autres formulaire de la meme catégorie.
 */
class DescriptionGeoWidget : public ToolBoxWidget
{
    Q_OBJECT
public:
    explicit DescriptionGeoWidget(Data * data, QWidget *parent = 0);

    /**
     * @brief Initialise les formulaire avec les valeurs de l'objet Data
     */
    void init();
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


private:
    FormVolumeCalcul * formVolCal;
    FormParoi * formParoi;
    
};

#endif // DESCRIPTIONGEOWIDGET_H
