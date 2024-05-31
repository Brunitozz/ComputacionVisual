#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    glutInitWindowPosition(centerX - 400, centerY - 300);
    glutCreateWindow("Ventana centrada");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // parámetros: rojo, verde, azul, alfa
    glShadeModel(GL_FLAT);
}

void display(void) {

    GLUquadricObj* pt;
    pt = gluNewQuadric();
    GLdouble rinterior = 0;
    GLdouble rexterior = 9;
    GLint nlados = 15;
    GLint nvueltas = 6;

    GLfloat ang, r = 8.0f, x, y;

    gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f(0.0, 1.0, .0);
    gluDisk(pt, rinterior, rexterior, nlados, nvueltas);
    glColor3f(1.0, 0.0, .0);
    glBegin(GL_LINE_STRIP);
    for (ang = 0.0f; ang < 2 * M_PI; ang += 2 * M_PI / 1000) {
        //float r = ang;
        float r = -5 * cos(ang) + cos(5 * ang);
        //float r = 3 - 3 * cos(ang);
        float x = r * cos(ang);
        float y = r * sin(ang);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
