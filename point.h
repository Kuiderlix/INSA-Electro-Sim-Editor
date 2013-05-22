#ifndef POINT_H
#define POINT_H

/**
 * @brief Cette classe représente un point dans un espace en 3D.
 * Elle est utilisé pour afficher les Cube dans la vue 3D.
 */
class Point
{
public:
    Point();
    Point(float _x, float _y, float _z);

    float x,y,z;
};

#endif // POINT_H
