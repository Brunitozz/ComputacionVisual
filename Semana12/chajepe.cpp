#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);
void drawCircle(float, float, float);
void translateFigure(float, float, float &, float &);

float tx = 5.0f; // traslación en x
float ty = 5.0f; // traslación en y

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traslación de Figuras");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // parámetros: rojo, verde, azul, alfa
    glShadeModel(GL_SMOOTH);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // guarda el estado actual de la matriz

    glLineWidth(2);
    glColor3f(0.0, 0.0, 1.0);

    // Dibuja el círculo original en el origen (0, 0)
    drawCircle(0, 0, 10);

    // Aplica la traslación y dibuja el círculo trasladado
    translateFigure(tx, ty, 0, 0);
    drawCircle(tx, ty, 10);

    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void drawCircle(float h, float k, float r) {
    GLfloat x, y;
    glBegin(GL_LINE_LOOP);
    for (GLfloat ang = 0.0f; ang < 2 * M_PI; ang += 2 * M_PI / 1000) {
        x = r * cos(ang);
        y = r * sin(ang);
        glVertex2f(x + h, y + k);
    }
    glEnd();
}

void translateFigure(float tx, float ty, float &x, float &y) {
    // Aplica la traslación a los puntos x e y
    x += tx;
    y += ty;
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-20.0, 20.0, -20.0 * (GLfloat)h / (GLfloat)w, 20.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-20.0 * (GLfloat)w / (GLfloat)h, 20.0 * (GLfloat)w / (GLfloat)h, -20.0, 20.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
