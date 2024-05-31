#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define GL_PI M_PI

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // parámetros: rojo, amarillo, azul, el cuarto es el parámetro alpha
    glShadeModel(GL_FLAT);
}

void display(void) {
    GLfloat ang, radio = 10.0f, x, y;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // salva el estado actual de la matriz
    glBegin(GL_POINTS);
    for (ang = 0.0f; ang < 2 * GL_PI; ang += 2 * GL_PI /1000)
    {
        x = radio * sin(ang);
        y = radio * cos(ang);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}