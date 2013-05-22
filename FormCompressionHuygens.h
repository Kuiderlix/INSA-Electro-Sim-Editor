#ifndef FORMCOMPRESSIONHUYGENS_H
#define FORMCOMPRESSIONHUYGENS_H

#include <QtWidgets>
#include "compressionHuygens.h"

/**
 * @brief Cette classe fournit un formulaire pour modifier l'objet compressionHuygens
 */
class FormCompressionHuygens : public QWidget
{
    Q_OBJECT
public:
    explicit FormCompressionHuygens(compressionHuygens * compreHuy, QWidget *parent = 0);

    void setCompressHuy(compressionHuygens* c)
    {
        compreHuy=c;
        init();
    }
    
    void init();
signals:
    
public slots:
    

private:
    compressionHuygens * compreHuy;

    QSpinBox * compLongWidget;
    QSpinBox * compLargWidget;
    QSpinBox * compHautWidget;
    QSpinBox * facteurMultiWidget;
};

#endif // FORMCOMPRESSIONHUYGENS_H
