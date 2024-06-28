#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

std::vector<int> pointsX;
std::vector<int> pointsY;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-40, 100, -60, 100);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < pointsX.size(); i++)
    {
        glVertex2i(pointsX[i], pointsY[i]);
    }
    glEnd();
    glFlush();
}

void mouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);

        double modelview[16];
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);

        double projection[16];
        glGetDoublev(GL_PROJECTION_MATRIX, projection);

        float winX = (float)x;
        float winY = (float)viewport[3] - (float)y; 

        double posX, posY, posZ;
        gluUnProject(winX, winY, 0.0, modelview, projection, viewport, &posX, &posY, &posZ);

        pointsX.push_back((int)posX);
        pointsY.push_back((int)posY);

        glutPostRedisplay(); 
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Puntos graficados con el mouse");
    inicio();
    glutDisplayFunc(pantalla);
    glutMouseFunc(mouseFunc);
    glutMainLoop();
    return EXIT_SUCCESS;
}
