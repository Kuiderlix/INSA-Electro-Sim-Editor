#ifndef FORMVOLUMECALCUL_H
#define FORMVOLUMECALCUL_H

#include <QtWidgets>
#include "volumeCalcul.h"
class FormVolumeCalcul : public QWidget
{
    Q_OBJECT
public:
    explicit FormVolumeCalcul(volumeCalcul * volCal, QWidget *parent = 0);
    
signals:
    
public slots:

private:
    volumeCalcul * volCal;
    
};

#endif // FORMVOLUMECALCUL_H
