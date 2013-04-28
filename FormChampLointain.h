#ifndef FORMCHAMPLOINTAIN_H
#define FORMCHAMPLOINTAIN_H

#include <QtWidgets>
#include "champLointain.h"
#include "FormCoordonnees.h"

class FormChampLointain : public QWidget
{
    Q_OBJECT
public:
    explicit FormChampLointain(champLointain * champ, QWidget *parent = 0);
    
signals:
    
public slots:
private:
    champLointain * champ;
    
};

#endif // FORMCHAMPLOINTAIN_H
