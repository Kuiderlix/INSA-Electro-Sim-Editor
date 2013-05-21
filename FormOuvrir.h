#ifndef OUVRIRFORM_H
#define OUVRIRFORM_H

#include <QtWidgets>

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

    void setNum(int i);

private:
    int num;

    QSpinBox * nbrSimu;

    QPushButton * validerBouton, * annulerBouton;
    
};

#endif // OUVRIRFORM_H
