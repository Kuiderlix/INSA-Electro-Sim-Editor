#ifndef NOUVEAUFORM_H
#define NOUVEAUFORM_H

#include <QtWidgets>

/**
 * @brief Cette classe est le formulaire pour ajouter une nouvelle simulation
 */
class FormNouveau : public QDialog
{
    Q_OBJECT
public:
    explicit FormNouveau(QWidget *parent = 0);

    int getNum()
    {
        return num;
    }
    
signals:
    
public slots:

    void testFichierExistant(int n);
    void setNum(int i);

private:
    int num;
    QSpinBox * nbrSimu;

    QLabel * labelFichierExist;

    QPushButton * validerBouton, * annulerBouton;

    
};

#endif // NOUVEAUFORM_H
