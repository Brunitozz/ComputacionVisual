#include <windows.h>
#include <GL/glut.h>
#include <math.h>
void inicio()
{
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-50,150,-100,150);
 glClearColor(0.0,0.0,1.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(100.0,0.0,0.0);
        glVertex3f(50.0,100.0,0.0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Triangulo usando la función GL_TRIANGLES");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}