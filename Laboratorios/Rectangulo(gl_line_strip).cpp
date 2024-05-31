#include <windows.h>
#include <GL/glut.h>
void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100,150,-50,150);
    glClearColor(0.0,0.0,1.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0,50.0);
        glVertex2f(0.0,0.0);
        glVertex2f(70.0,0.0);
        glVertex2f(70.0,100.0);
        glVertex2f(0.0,100.0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Rectángulo inconcluso con la función GL_LINE_STRIP");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}