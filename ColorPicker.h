#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QPushButton>
#include <QColorDialog>
#include <QPainter>
#include <QPaintEvent>

/**
 * @brief Cette classe est un widget sous forme de bouton qui permet de
 * sélectionner une couleur dans une boite de dialogue qui s'ouvre quand le bouton est pressé.
 * Un carré de la couleur sélectionnée est présent sur le bouton.
 */
class ColorPicker : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorPicker(QColor c,QWidget *parent = 0);

    /**
     * @brief Dessine le carré avec la couleur sélectionnée sur le bouton
     */
    void paintEvent(QPaintEvent *);

    /**
     * @brief Change la couleur courante
     * @param c la nouvelle couleur
     */
    void setColor(QColor c)
    {
        couleur=c;
    }
    
signals:

    /**
     * @brief Ce signal est émis quand la couleur change
     */
    void colorChanged(QColor);
    
public slots:
    /**
     * @brief Cette fonction ouvre la boite de dialogue pour changer de couleur et met à jour la couleur courante.
     *
     */
    void ouvreColorDialog();

private:
    /**
     * @brief La couleur courante
     */
    QColor couleur;
    
};

#endif // COLORPICKER_H
