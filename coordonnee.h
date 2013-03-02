/* 
 * File:   coordonnee.h
 * Author: camille
 *
 * Created on February 26, 2013, 5:38 PM
 */

#ifndef COORDONNEE_H
#define	COORDONNEE_H

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

private:
    int x;
    int y;
    int z;
};

#endif	/* COORDONNEE_H */

