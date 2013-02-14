#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QtGui>

class Formulaire : public QWidget
{
    Q_OBJECT
public:
    explicit Formulaire(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QVBoxLayout * layoutPrincipale;
    
};

#endif // FORMULAIRE_H
