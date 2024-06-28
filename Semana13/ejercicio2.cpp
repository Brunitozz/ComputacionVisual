#include <GL/glut.h>
#include <stdio.h>

// Función de callback para el teclado
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {  // ESC para salir
        exit(0);
    }
}

// Función de callback para el ratón
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("Botón izquierdo del ratón presionado en (%d, %d)\n", x, y);
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        printf("Botón derecho del ratón presionado en (%d, %d)\n", x, y);
    }
}

// Función de callback para el movimiento del ratón con botones presionados
void motion(int x, int y) {
    printf("Movimiento del ratón con botón presionado en (%d, %d)\n", x, y);
}

// Función de callback para el movimiento del ratón sin botones presionados
void passiveMotion(int x, int y) {
    printf("Movimiento del ratón sin botón presionado en (%d, %d)\n", x, y);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Eventos del ratón y teclado en GLUT");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);  // Asignar la función de callback para el movimiento del ratón con botón presionado
    glutPassiveMotionFunc(passiveMotion);  // Asignar la función de callback para el movimiento del ratón sin botón presionado
    glutMainLoop();
    return 0;
}