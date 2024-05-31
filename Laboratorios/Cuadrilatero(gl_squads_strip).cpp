#include <windows.h>
#include <GL/glut.h>
void inicio()
{
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-40,100,-60,100);
 glClearColor(0.0,0.0,0.0,0.0);
}
void pantalla()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_QUAD_STRIP);
 glVertex3f(0.0,0.0,0.0); //Observe que el siguiente vértice no sigue la secuencia recomendada
 glVertex3f(0.0,50.0,0.0);
 glVertex3f(30.0,0.0,0.0); //Esto se debe a que debe mantener los dos últimos vértices para generar un nuevo cuadrilátero si es necesario.
 glVertex3f(30.0,50.0,0.0);
 //glVertex3f(60.0,0.0,0.0); //Si se le agrega esta coordenada y la siguiente, se construirá un nuevo cuadrilátero partiendo de los dos últimos vértices
 //glVertex3f(60.0,50.0,0.0);
 glEnd();
 /*glColor3f(0.0,0.0,0.0); //Quite los caracteres de comentario de este bloque de instrucciones para visualizar una línea que permita visualizar la división
 glBegin(GL_LINES);
 glVertex3f(30.0,0.0,0.0);
 glVertex3f(30.0,50.0,0.0);
 glEnd();*/
 glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Cuadrilátero graficado con función QUAD_STRIP y relleno amarillo");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}