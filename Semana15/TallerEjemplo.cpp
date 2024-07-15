#include <stdlib.h>
#include <GL/glut.h>

// Declaración de variables
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint eje = 2;
static int delay = 100; // Milisegundos entre cada actualización
static GLfloat scale = 0.01;

// Función para dibujar una cara del cubo
void cara(GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[], GLfloat color[])
{
    glBegin(GL_POLYGON);
    glColor3fv(color);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3fv(v3);
    glVertex3fv(v4);
    glEnd();
}

// Función para construir el cubo
void cubo(void)
{
    GLfloat v[8][3] = {
        {-0.5, -0.5,  0.5},
        { 0.5, -0.5,  0.5},
        { 0.5,  0.5,  0.5},
        {-0.5,  0.5,  0.5},
        {-0.5, -0.5, -0.5},
        { 0.5, -0.5, -0.5},
        { 0.5,  0.5, -0.5},
        {-0.5,  0.5, -0.5}
    };

    GLfloat colores[6][3] = {
        {1.0, 0.0, 0.0}, // Rojo
        {0.0, 1.0, 0.0}, // Verde
        {0.0, 0.0, 1.0}, // Azul
        {1.0, 1.0, 0.0}, // Amarillo
        {1.0, 0.0, 1.0}, // Magenta
        {0.0, 1.0, 1.0}  // Cian
    };

    cara(v[0], v[1], v[2], v[3], colores[0]);
    cara(v[4], v[5], v[6], v[7], colores[1]);
    cara(v[0], v[1], v[5], v[4], colores[2]);
    cara(v[2], v[3], v[7], v[6], colores[3]);
    cara(v[0], v[3], v[7], v[4], colores[4]);
    cara(v[1], v[2], v[6], v[5], colores[5]);
}

// Función para dibujar los ejes coordenados
void dibujarEjes(void)
{
    glBegin(GL_LINES);

    // Eje X en rojo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);

    // Eje Y en verde
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);

    // Eje Z en azul
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(0.0, 0.0, 1.0);

    glEnd();
}

// Dibujamos nuestra escena
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Composición de rotaciones
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    // Rotación en el eje seleccionado
    // glRotatef(theta[eje], (eje == 0), (eje == 1), (eje == 2));
    // Escalado del cubo
    glScaled(scale, scale, scale);

    // Dibujar ejes y cubo
    dibujarEjes();
    cubo();

    glFlush();
    glutSwapBuffers();
}

void scaleCube()
{
    glLoadIdentity();
    for (GLfloat i = 0; i < 5; i += 0.1)
    {
        glPushMatrix();
        glScalef(0.5, i, 0.5);
        display();
        glPopMatrix();
    }
}

// Controla el ángulo de rotación según el eje de giro
void girar_objeto_geometrico(int value)
{
    theta[eje] += 7; // Incremento más pequeño para una rotación más lenta
    if (theta[eje] > 360) theta[eje] -= 360.0;
    display();
    glutTimerFunc(delay, girar_objeto_geometrico, 0); // Llamar a la función nuevamente después de `delay` milisegundos
}

// Función para el control del teclado
void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla) {
    case 'a': eje = 0; break;
    case 's': eje = 1; break;
    case 'd': eje = 2; break;
    case '-': scale -= 0.01; break;
    case '+': scale += 0.01; break;
    case 'f': exit(0); break;
    }
}

// Control de ventana (volumen de visualización)
void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cubo bajo rotaciones");

    // Configuración de las funciones de GLUT
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

    glEnable(GL_DEPTH_TEST);

    // Usar glutTimerFunc para controlar la velocidad de rotación
    glutTimerFunc(delay, girar_objeto_geometrico, 0);

    glutMainLoop();
    return 0;
}
