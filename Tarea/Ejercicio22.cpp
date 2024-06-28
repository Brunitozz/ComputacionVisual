#include <GL/glut.h>
#include <iostream>


using namespace std;


int radio;


void inicializar() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}


void circuloConPuntoMedio(int xc, int yc, int R) {
    int x = 0;
    int y = R;
    int d = 1 - R;


    glColor3f(0, 0, 1);
    glPointSize(3);


    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}


void pantalla() {

    glClear(GL_COLOR_BUFFER_BIT);
    circuloConPuntoMedio(0, 0, radio);
    glFlush();
}


int main(int argc, char *argv[]) {
    cout << "Radio de la circunferencia: ";
    cin >> radio;


    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Circunferencia con Punto Medio");
    inicializar();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
