#ifndef FORMPAROI_H
#define FORMPAROI_H

#include <QtWidgets>
#include "paroi.h"

class FormParoi : public QWidget
{
    Q_OBJECT
public:
    explicit FormParoi(paroi* m_paroi, QWidget *parent = 0);
    
signals:
    
public slots:


private:
    paroi* m_paroi;
    
};

#endif // FORMPAROI_H
