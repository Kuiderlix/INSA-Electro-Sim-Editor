#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QtWidgets>

/**
 * @brief Cette classe est le formulaire pour modifier les paramètres du logiciel
 */
class FormSettings : public QDialog
{
    Q_OBJECT
public:
    explicit FormSettings(QWidget *parent = 0);
    
signals:
    
public slots:
    void ouvreDialogDossier();
    void appliquer();

private:
    QLineEdit * champsPathSimu;

    QPushButton *appliquerBouton, *annulerBouton, *OKBouton;

    QSettings* settings;
    
};

#endif // FORMSETTINGS_H
