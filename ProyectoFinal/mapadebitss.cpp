#include <stdlib.h>
#include <conio.h>
#include <gl/glut.h>

// Global variables for window width and height

static GLfloat theta[] = { 0.0, 0.0, 0.0 };
//eje es el angulo de rotacion
static GLint eje = 2;

//Construya el polgono base
void cara() {
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, 0.0);
    glEnd();
}

//construya su objeto geometrico mediante cubo()

void cubo(void) {
    cara();
}