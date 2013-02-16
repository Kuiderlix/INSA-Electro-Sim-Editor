#ifndef CUBE_H
#define CUBE_H

#include <QtOpenGL>
#include "point.h"

class Cube
{
public:
    Cube();

    void dessineCube();

private:
    Point topLeftCorner, bottomRightCorner; // définition d'un cube avec les données des fichiers de config
};

#endif // CUBE_H
