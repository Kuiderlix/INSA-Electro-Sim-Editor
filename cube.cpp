#include "cube.h"

Cube::Cube()
{
    topLeftCorner.x=-1.0;
    topLeftCorner.y=-1.0;
    topLeftCorner.z=-1.0;

    bottomRightCorner.x=1.0;
    bottomRightCorner.y=1.0;
    bottomRightCorner.z=1.0;

}

Cube::Cube(Point p1, Point p2)
{
    topLeftCorner = p1;
    bottomRightCorner = p2;
}


void Cube::dessineCube()
{
  /*
    y
    |   z
    |  /
    | /
    |/
    |________x

   */
    glBegin(GL_QUADS);
            // Face Avant
           glColor3f(0.0f, 0.0f, 0.0f);

           glVertex3f(topLeftCorner.x,      topLeftCorner.y,        topLeftCorner.z);
           glVertex3f(topLeftCorner.x,      bottomRightCorner.y,    topLeftCorner.z);
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    topLeftCorner.z);
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,        topLeftCorner.z);

           // Face Arrière
           glVertex3f(topLeftCorner.x,      topLeftCorner.y,        bottomRightCorner.z);
           glVertex3f(topLeftCorner.x,      bottomRightCorner.y,    bottomRightCorner.z);
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    bottomRightCorner.z);
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,        bottomRightCorner.z);


           // Face Bas
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,     bottomRightCorner.z);
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,     topLeftCorner.z);
           glVertex3f(topLeftCorner.x,      topLeftCorner.y,     topLeftCorner.z);
           glVertex3f(topLeftCorner.x,      topLeftCorner.y,     bottomRightCorner.z);

           // Face Haut
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    bottomRightCorner.z);
           glVertex3f(topLeftCorner.x,      bottomRightCorner.y,    bottomRightCorner.z);
           glVertex3f(topLeftCorner.x,      bottomRightCorner.y,    topLeftCorner.z);
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    topLeftCorner.z);

           // Face Gauche
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,        bottomRightCorner.z);
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    bottomRightCorner.z);
           glVertex3f(bottomRightCorner.x,  bottomRightCorner.y,    topLeftCorner.z);
           glVertex3f(bottomRightCorner.x,  topLeftCorner.y,        topLeftCorner.z);

           // Face Droite
           glVertex3f(topLeftCorner.x, topLeftCorner.y, bottomRightCorner.z);
           glVertex3f(topLeftCorner.x, topLeftCorner.y, topLeftCorner.z);
           glVertex3f(topLeftCorner.x,  bottomRightCorner.y, topLeftCorner.z);
           glVertex3f(topLeftCorner.x,  bottomRightCorner.y, bottomRightCorner.z);

       glEnd();
}
