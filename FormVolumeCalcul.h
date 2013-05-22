#ifndef FORMVOLUMECALCUL_H
#define FORMVOLUMECALCUL_H

#include <QtWidgets>
#include "volumeCalcul.h"

/**
 * @brief Cette classe fournit un formulaire pour modifier l'objet volumeCalcul
 */
class FormVolumeCalcul : public QWidget
{
    Q_OBJECT
public:
    explicit FormVolumeCalcul(volumeCalcul * volCal, QWidget *parent = 0);

    void setVolumeCalcul(volumeCalcul * vol)
    {
        volCal=vol;
        init();
    }

    void init();
    
signals:
    
public slots:

private:
    volumeCalcul * volCal;

    QDoubleSpinBox * longueurWidget;
    QDoubleSpinBox * largeurWidget;
    QDoubleSpinBox * hauteurWidget;

    QSpinBox * nbrYWidget;
    QSpinBox * nbrXWidget;
    QSpinBox * nbrZWidget;
    
};

#endif // FORMVOLUMECALCUL_H
