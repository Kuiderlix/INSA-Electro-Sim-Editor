#ifndef OUVRIRFORM_H
#define OUVRIRFORM_H

#include <QtWidgets>

/**
 * @brief Cette classe est le formulaire pour ouvrir une nouvelle simulation
 */
class FormOuvrir : public QDialog
{
    Q_OBJECT
public:
    explicit FormOuvrir(QWidget *parent = 0);

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

#endif // OUVRIRFORM_H
