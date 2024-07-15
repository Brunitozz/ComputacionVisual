#include <GL/glut.h>
#include <cmath>
#include <cstdlib>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


const float a = 1.0f;


void dibujarEjes(){
   
    glLineWidth(2);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(-80, 0);
    glVertex2i(80, 0);
    glVertex2i(0, -80);
    glVertex2i(0, 80);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
   
    dibujarEjes();
    int puntos = 100;
    float theta, r, x ,y= 0.2f;
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
        for(theta = 0.0f; theta < 2*M_PI; theta+=0.0005) {
            x = 2 *(2*cos(2*theta)) * cos(3*theta);
            y = 2 *(2*sin(4*theta)) * cos(5*theta);
            glVertex2f(x, y);
        }


    glEnd();
    glFlush();
}


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-12.0, 12.0, -12.0, 12.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Globos");


    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
