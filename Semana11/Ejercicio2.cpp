#include <GL/glut.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define GL_PI M_PI

const int num_points = 1000;
const float theta_min = 0.0f;
const float theta_max = 2.0f * M_PI;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //GLUquadricObj* pt;
    //pt = gluNewQuadric();
   // gluQuadricDrawStyle(pt, GLU_LINE);
    glColor3f(1.0, 0.0, 0.0);
    //gluPartialDisk(pt, 0, 0.7, 20, 10, 0, 360);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= num_points; ++i) {
        float theta = theta_min + (theta_max - theta_min) * i / num_points;
        float r = 5;
        float x = r * (1 - cos(theta)) * cos(theta);
        float y = r * (1 - cos(3 * theta)) * sin(3 * theta);
        glVertex2f(x / 10.0f, y / 10.0f);
    }
    glEnd();

    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cardioide");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Ajustar el rango de visualización para x e y
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
