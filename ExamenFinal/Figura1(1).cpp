#include <GL/glut.h>
#include <cmath>
#include <sstream>
#include <string>

float q = 1, w = 6, e = 7, a = 1, s = 6, d = 7;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Blanco
    glColor3f(0.0, 0.0, 0.0); // Negro para las líneas
    glLineWidth(2.0); // Grosor de las líneas
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':
        q+=.1;
        break;
    case 'w':
        w+=.1;
        break;
    case 'e':
        e+=.1;
        break;
    case 'a':
        a+=.1;
        break;
    case 's':
        s+=.1;
        break;
    case 'd':
        d+=.1;
        break;


    case 'y':
        q-=.1;
        break;
    case 'u':
        w-=.1;
        break;
    case 'i':
        e-=.1;
        break;
    case 'h':
        a-=.1;
        break;
    case 'j':
        s-=.1;
        break;
    case 'k':
        d-=.1;
        break;
    }
    glutPostRedisplay(); // Solicitar redibujar la pantalla
}

void renderBitmapString(float x, float y, void *font, const char *string) {
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // Negro
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0); // Eje X
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0); // Eje Y
    glVertex2f(0.0, 1.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Rojo para el cardioide
    int points = 1000;
    float radius = 0.5f;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= points; ++i) {
        float theta = 2.0f * 3.1415f * float(i) / float(points);
        float x = radius * (q - cos(w * theta)) * sin(e * theta);
        float y = radius * (a - cos(s * theta)) * cos(d * theta);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.0, 0.0, 0.0); // Negro para el texto
    std::stringstream ss;
    ss << "q: " << q << " w: " << w << " e: " << e;
    std::string texta = ss.str();
    renderBitmapString(-0.9f, 0.9f, GLUT_BITMAP_HELVETICA_18, texta.c_str());

    std::stringstream tt;
    tt << " a: " << a << " s: " << s << " d: " << d;
    std::string textb = tt.str();
    renderBitmapString(-0.9f, 0.85f, GLUT_BITMAP_HELVETICA_18, textb.c_str());

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Figura 3");
    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
