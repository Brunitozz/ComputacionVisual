#include <GL/glut.h>
#include <math.h>
#include <vector>

// Longitud de la cuerda y ángulo inicial del péndulo
GLfloat longitudCuerda = 2.0;
GLfloat angulo = 30.0; // Ángulo inicial en grados
GLfloat velocidadAngular = 0.0; // Velocidad angular inicial
GLfloat gravedad = 9.8; // Aceleración debido a la gravedad
GLfloat deltaTiempo = 0.01; // Incremento de tiempo para cada actualización

// Variables para el control de la cámara
GLfloat cameraAngleX = 0.0;
GLfloat cameraAngleY = 0.0;
int lastMouseX = -1;
int lastMouseY = -1;

// Estructura para almacenar una posición en 3D
struct Position {
    GLfloat x, y, z;
};

// Vector para almacenar las posiciones anteriores del péndulo
std::vector<Position> rastroPendulo;

void actualizarPendulo() {
    // Convertir el ángulo a radianes
    GLfloat anguloRadianes = angulo * M_PI / 180.0;

    // Aceleración angular basada en la ecuación del péndulo simple
    GLfloat aceleracionAngular = -(gravedad / longitudCuerda) * sin(anguloRadianes);

    // Actualizar la velocidad angular y el ángulo
    velocidadAngular += aceleracionAngular * deltaTiempo;
    angulo += velocidadAngular * deltaTiempo * 180.0 / M_PI;

    // Calcular la nueva posición del extremo del péndulo
    GLfloat x = longitudCuerda * sin(anguloRadianes);
    GLfloat y = -longitudCuerda * cos(anguloRadianes);

    // Añadir la nueva posición al rastro del péndulo
    rastroPendulo.push_back({x, y, 0.0});

    // Limitar el tamaño del rastro del péndulo para evitar consumir demasiada memoria
    if (rastroPendulo.size() > 1000) {
        rastroPendulo.erase(rastroPendulo.begin());
    }

    // Redistribuir la pantalla
    glutPostRedisplay();
}

void drawPendulo() {
    // Convertir el ángulo a radianes
    GLfloat radianes = angulo * M_PI / 180.0;

    // Coordenadas del extremo inferior del péndulo
    GLfloat x = longitudCuerda * sin(radianes);
    GLfloat y = -longitudCuerda * cos(radianes);

    // Dibujar la cuerda
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(x, y, 0.0);
    glEnd();

    // Dibujar la esfera en el extremo del péndulo
    glTranslatef(x, y, 0.0);
    glutSolidSphere(0.1, 20, 20); // Radio de la esfera, resolución
}

void drawRastro() {
    glColor3f(0.0, 0.0, 1.0); // Color azul para el rastro
    glBegin(GL_LINE_STRIP);
    for (const auto& pos : rastroPendulo) {
        glVertex3f(pos.x, pos.y, pos.z);
    }
    glEnd();
}

void drawAxes() {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    // Eje X en rojo
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    // Eje Y en verde
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    // Eje Z en azul
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 2.0);
    glEnd();
    glLineWidth(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Configurar la cámara
    gluLookAt(0.0, 0.0, 5.0,  // Posición de la cámara
              0.0, 0.0, 0.0,  // Hacia dónde mira la cámara
              0.0, 1.0, 0.0); // Vector "arriba" de la cámara

    // Aplicar la rotación de la cámara basada en el movimiento del mouse
    glRotatef(cameraAngleX, 1.0, 0.0, 0.0);
    glRotatef(cameraAngleY, 0.0, 1.0, 0.0);

    // Dibujar los ejes de coordenadas
    drawAxes();

    // Dibujar el rastro del péndulo
    drawRastro();

    // Dibujar el péndulo
    glColor3f(1.0, 0.0, 0.0); // Color rojo
    drawPendulo();

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

void timer(int value) {
    actualizarPendulo();
    glutTimerFunc(16, timer, 0); // Llamar a la función de temporizador cada 16 ms (~60 FPS)
}

void mouseMotion(int x, int y) {
    if (lastMouseX == -1 && lastMouseY == -1) {
        lastMouseX = x;
        lastMouseY = y;
        return;
    }

    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    cameraAngleX += dy * 0.1;
    cameraAngleY += dx * 0.1;

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Péndulo Simple");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMotionFunc(mouseMotion);

    glEnable(GL_DEPTH_TEST);

    init();
    glutTimerFunc(16, timer, 0); // Iniciar el temporizador
    glutMainLoop();
    return 0;
}
