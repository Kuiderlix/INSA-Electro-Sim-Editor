#ifndef NOUVEAUFORM_H
#define NOUVEAUFORM_H

#include <QtWidgets>

class FormNouveau : public QDialog
{
    Q_OBJECT
public:
    explicit FormNouveau(QWidget *parent = 0);
    
signals:
    
public slots:

private:
    QSpinBox * nbrSimu;

    QPushButton * validerBouton, * annulerBouton;
    
};

#endif // NOUVEAUFORM_H
