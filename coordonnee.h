/* 
 * File:   coordonnee.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:38 PM
 */

#ifndef COORDONNEE_H
#define	COORDONNEE_H
#include <QVariant>
#include <QString>

class coordonnee {
public:
    coordonnee();
    coordonnee(int x, int y, int z);
    coordonnee(const coordonnee& orig);
    virtual ~coordonnee();

    int GetX() const {
        return x;
    }

    void SetX(int x) {
        this->x = x;
    }

    int GetY() const {
        return y;
    }

    void SetY(int y) {
        this->y = y;
    }

    int GetZ() const {
        return z;
    }

    void SetZ(int z) {
        this->z = z;
    }

    QString toQString()
    {
        return QString().append("(x:").append(QString::number(x)).append(", y:").append(QString::number(y)).append(", z:").append(QString::number(z)).append(")");
    }

    bool operator==(coordonnee const& b);

    void ecrire();

private:
    int x;
    int y;
    int z;
};
Q_DECLARE_METATYPE(coordonnee)
#endif	/* COORDONNEE_H */

