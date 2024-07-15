#include <GL/glut.h>
#include <math.h>

GLfloat lado = 1;
int numSquares = 50; // Número de cuadrados concéntricos
float angle = 0.0; // Ángulo de rotación inicial

void drawSquare(double lado) {
    // Dibujar el contorno del cuadrado
    glBegin(GL_LINE_LOOP);
    glVertex2f(-lado / 2, -lado / 2);
    glVertex2f(lado / 2, -lado / 2);
    glVertex2f(lado / 2, lado / 2);
    glVertex2f(-lado / 2, lado / 2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -4.0);
    glColor3f(1.0, 0.0, 0.0); // Color rojo

    for (int i = 0; i < numSquares; ++i) {
        glPushMatrix(); // Guardar el estado actual de la matriz
        glRotatef(i * 15, 0.0, 0.0, 1.0); // Rotar en sentido antihorario
        drawSquare(lado - i * (lado / numSquares)); // Dibujar cuadrado con tamaño reducido
        glPopMatrix(); // Restaurar el estado anterior de la matriz
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cuadrados Concéntricos");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}
