#ifndef TABLEMETALLISATION_H
#define TABLEMETALLISATION_H

#include <QTableWidget>
#include "blocMetallisation.h"

class TableMetallisation : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableMetallisation(QWidget *parent = 0);
    
signals:
    
public slots:

    blocMetallisation* listeMetallisation;
    
};

#endif // TABLEMETALLISATION_H
