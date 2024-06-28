#include <GL/glut.h>
#include <iostream>


using namespace std;


float color[3];
int grosor;
int radius;


void inicializar() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}


void circulo_punto_medio(int xc, int yc, int R) {
    int x = 0;
    int y = R;
    int d = 1 - R;


    glColor3f(color[0], color[1], color[2]);
    glPointSize(grosor);


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
    circulo_punto_medio(0, 0, radius);
    glFlush();
}


int main(int argc, char *argv[]) {
    cout << "Ingrese el radio de la circunferencia: ";
    cin >> radius;
    cout << "Ingrese los valores de color (RGB) entre 0 y 1: ";
    cin >> color[0] >> color[1] >> color[2];
    cout << "Ingrese el grosor de la línea: ";
    cin >> grosor;


    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Circunferencia con Punto Medio");
    inicializar();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
};