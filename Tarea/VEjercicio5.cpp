#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;


int a, b, centrox, centroy;
void init(void);
void display(void);
void reshape(int, int);
void dibujarElipse(int, int, int, int);
void puntoMedioElipse(float, float);
void algoritmoElipseParametricas(int cx, int cy, int a, int b);
void recibirDatos();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Elipse con parametricas");
	init();
	recibirDatos();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);
}


void recibirDatos(){
	cout<<"\tCentro en el eje x: "; std::cin>>centrox;
	cout<<"\tCentro en el eje y: "; std::cin>>centroy;
	cout<<"\tValor de a: "; std::cin>>a;
	cout<<"\tValor de b: "; std::cin>>b;
	cout<<"Presione Enter para ingresar nuevas coordenadas\n";
}

void algoritmoElipseParametricas(int cx, int cy, int a, int b){
	int x, y;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (float t = 0; t <= 2*M_PI; t += 0.1) {
        x = cx + a*cos(t);
        y = cy + b*sin(t);
        glVertex2f(x, y);
	}
	glEnd();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	algoritmoElipseParametricas(centrox, centroy, a, b);
	glFlush();
}

void keyboard(unsigned char key, int x, int y){
	if (key == '\r' || key == '\n'){
		recibirDatos();
		glutPostRedisplay();
	}
}



void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -300.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void dibujarElipse(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
    glPointSize(2);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glEnd();
}

void puntoMedioElipse(float a, float b) {
    float x = 0;
    float y = b;
    float a2 = a * a;
    float b2 = b * b;
    float fx = 0;
    float fy = 2 * a2 * y;

    // Primera región
    float p = b2 - (a2 * b) + (0.25 * a2);
    while (fx < fy) {
        dibujarElipse(x, y, 0, 0);
        x++;
        fx += 2 * b2;
        if (p < 0) {
            p += b2 + fx;
        } else {
            y--;
            fy -= 2 * a2;
            p += b2 + fx - fy;
        }
    }

    // Segunda región
    p = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y > 0) {
        dibujarElipse(x, y, 0, 0);
        y--;
        fy -= 2 * a2;
        if (p >= 0) {
            p += a2 - fy;
        } else {
            x++;
            fx += 2 * b2;
            p += a2 - fy + fx;
        }
    }
}

void ingresoDatos(void) {
    cout << "Ingrese el valor de a (semi-eje mayor): ";
    cin >> a;
    cout << "Ingrese el valor de b (semi-eje menor): ";
    cin >> b;
}
