#ifndef FORMSURFACEPRELEVEMENT_H
#define FORMSURFACEPRELEVEMENT_H

#include "FormElementBase.h"
#include "surfacePrelevement.h"

/**
 * @brief Formulaire permettant d'ajouter un nouvelle objet surfacePrelevement dans la scène 3D
 */
class FormSurfacePrelevement : public FormElementBase
{
    Q_OBJECT
public:
    FormSurfacePrelevement(surfacePrelevement * surface, QWidget* parent=0);

signals:

public slots:
    void valider();
    void reset();

    void activeResteForm(int val);

private:

    void init();

    surfacePrelevement * surface;
    QWidget * resteForm;

    QComboBox * typeSurfaceWidget;
    QLineEdit * nomFichierWidget;
    QSpinBox * insideOutsideWidget;
    QComboBox * nbFacesWidget;
    QDoubleSpinBox * compressionLongueurWidget;
    QDoubleSpinBox * compressionLargeurWidget;
    QDoubleSpinBox * compressionHauteurWidget;
};

#endif // FORMSURFACEPRELEVEMENT_H
