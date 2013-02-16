#include "cube.h"

Cube::Cube()
{
}


void Cube::dessineCube()
{
    glBegin(GL_QUADS);
           // Face Avant
           glColor3f(1.0f, 0.0f, 0.0f);
           glVertex3f(-1.0f, -1.0f,  1.0f);
           glVertex3f( 1.0f, -1.0f,  1.0f);
           glVertex3f( 1.0f,  1.0f,  1.0f);
           glVertex3f(-1.0f,  1.0f,  1.0f);

           // Face Arrière
           glColor3f(1.0f, 1.0f, 0.0f);
           glVertex3f(-1.0f, -1.0f, -1.0f);
           glVertex3f(-1.0f,  1.0f, -1.0f);
           glVertex3f( 1.0f,  1.0f, -1.0f);
           glVertex3f( 1.0f, -1.0f, -1.0f);

           // Face Haut
           glColor3f(1.0f, 0.0f, 1.0f);
           glVertex3f(-1.0f,  1.0f, -1.0f);
           glVertex3f(-1.0f,  1.0f,  1.0f);
           glVertex3f( 1.0f,  1.0f,  1.0f);
           glVertex3f( 1.0f,  1.0f, -1.0f);

           // Face Bas
           glColor3f(0.3f, 1.0f, 0.7f);
           glVertex3f(-1.0f, -1.0f, -1.0f);
           glVertex3f( 1.0f, -1.0f, -1.0f);
           glVertex3f( 1.0f, -1.0f,  1.0f);
           glVertex3f(-1.0f, -1.0f,  1.0f);

           // Face Droite
           glColor3f(0.3f, 0.0f, 0.3f);
           glVertex3f( 1.0f, -1.0f, -1.0f);
           glVertex3f( 1.0f,  1.0f, -1.0f);
           glVertex3f( 1.0f,  1.0f,  1.0f);
           glVertex3f( 1.0f, -1.0f,  1.0f);

           // Face Gauche
           glColor3f(1.0f, 0.0f, 0.2f);
           glVertex3f(-1.0f, -1.0f, -1.0f);
           glVertex3f(-1.0f, -1.0f,  1.0f);
           glVertex3f(-1.0f,  1.0f,  1.0f);
           glVertex3f(-1.0f,  1.0f, -1.0f);
       glEnd();
}
